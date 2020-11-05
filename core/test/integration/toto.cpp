/*
 *
 * toto.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 15/09/2020.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <gtest/gtest.h>
#include "BaseFixture.h"
#include <UvThreadDispatcher.hpp>
#include "IntegrationEnvironment.h"
#include <limits>
#include <iostream>

using namespace ledger::core;

struct TotoFixture : public BaseFixture {

};

static void press_enter(const std::string& message = "") {
    std::cout << "Press Enter to Continue (" << message << ")" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

static void synchronize(const std::shared_ptr<BitcoinLikeAccount>& account) {
    Promise<Unit> promise;
    auto bus = account->synchronize();
    auto receiver = make_receiver([=](const std::shared_ptr<api::Event> &event) mutable {
        fmt::print("HELLO {}\n", api::to_string(event->getCode()));
        if (event->getCode() == api::EventCode::SYNCHRONIZATION_SUCCEED ||
            event->getCode() == api::EventCode::SYNCHRONIZATION_SUCCEED_ON_PREVIOUSLY_EMPTY_ACCOUNT) {
           promise.success(unit);
           return;
        } else if (event->getCode() == api::EventCode::SYNCHRONIZATION_FAILED) {
            promise.failure(make_exception(api::ErrorCode::RUNTIME_ERROR, "Fail"));
            return ;
        }
    });
    bus->subscribe(account->getContext(), receiver);
    uv::wait(promise.getFuture());
    fmt::print("Balance: {}\n", uv::wait(account->getBalance())->toString());
}

TEST_F(TotoFixture, DO) {
    auto dispatcher = uv::createDispatcher();
    auto resolver = std::make_shared<NativePathResolver>(IntegrationEnvironment::getInstance()->getApplicationDirPath());
    auto printer = std::make_shared<CoutLogPrinter>(dispatcher->getMainExecutionContext());
    auto http = std::make_shared<CppHttpLibClient>(dispatcher->getMainExecutionContext());
    auto rng = std::make_shared<OpenSSLRandomNumberGenerator>();
    auto backend = std::static_pointer_cast<DatabaseBackend>(DatabaseBackend::getSqlite3Backend());

    auto pool = WalletPool::newInstance(
            "toto", "", http, nullptr, resolver, printer, dispatcher, rng, backend,
            api::DynamicObject::newInstance(), nullptr, nullptr);

    auto configuration = api::DynamicObject::newInstance();
    configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_API_ENDPOINT,"http://localhost:20000");
    configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_VERSION, "v3");
    configuration->putBoolean(api::Configuration::DEACTIVATE_SYNC_TOKEN, true);
    auto wallet = uv::wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "bitcoin_testnet",
                                          configuration));
    api::AccountCreationInfo keyInfo(
            0, {"main", "main"}, {"44'/1'/0'", "44'/1'"},
            {hex::toByteArray("0437bc83a377ea025e53eafcd18f299268d1cecae89b4f15401926a0f8b006c0f7ee1b995047b3e15959c5d10dd1563e22a2e6e4be9572aa7078e32f317677a901"), hex::toByteArray("04fb60043afe80ee1aeb0160e2aafc94690fb4427343e8d4bf410105b1121f7a44a311668fa80a7a341554a4ef5262bc6ebd8cc981b8b600dafd40f7682edb5b3b")},
            {hex::toByteArray("d1bb833ecd3beed6ec5f6aa79d3a424d53f5b99147b21dbc00456b05bc978a71"), hex::toByteArray("88c2281acd51737c912af74cc1d1a8ba564eb7925e0d58a5500b004ba76099cb")}
    );
    auto account = createBitcoinLikeAccount(wallet, 0, keyInfo);
    fmt::print("Address: {}\n", uv::wait(account->getFreshPublicAddresses())[0]->toString());
    synchronize(account);
    press_enter();
    synchronize(account);
    fmt::print("Send another transaction\n");
    press_enter();
    synchronize(account);
    fmt::print("Reorg\n");
    press_enter();
    synchronize(account);
    press_enter();
}