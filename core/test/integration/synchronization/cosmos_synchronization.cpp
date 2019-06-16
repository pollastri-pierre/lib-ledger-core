/*
 *
 * cosmos_synchronization.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 15/06/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
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
#include "../BaseFixture.h"
#include <set>
#include <api/KeychainEngines.hpp>
#include <utils/DateUtils.hpp>
#include <wallet/cosmos/explorers/NodeCosmosLikeBlockchainExplorer.h>
#include <wallet/cosmos/cosmosNetworks.h>
#include <collections/DynamicObject.hpp>
#include <iostream>
#include <cosmos/CosmosLikeExtendedPublicKey.h>
#include <wallet/currencies.hpp>
#include <wallet/cosmos/transaction_builders/CosmosLikeTransactionBuilder.h>
using namespace std;
using namespace ledger::core;

api::CosmosLikeNetworkParameters COSMOS = networks::getCosmosLikeNetworkParameters("cosmos");
std::string DEFAULT_ADDRESS = "cosmos16xkkyj97z7r83sx45xwk9uwq0mj0zszlf6c6mq";

class CosmosLikeWalletSynchronization : public BaseFixture {

};

TEST_F(CosmosLikeWalletSynchronization, GetAccountWithExplorer) {

    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<NodeCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient("https://stargate.cosmos.network"),
            COSMOS,
            std::make_shared<DynamicObject>()
            );

    auto account = ::wait(explorer->getAccount(DEFAULT_ADDRESS));
    ASSERT_EQ(account.address, DEFAULT_ADDRESS);
    ASSERT_EQ(account.accountNumber, "5859");

}


TEST_F(CosmosLikeWalletSynchronization, GetTransactionsWithExplorer) {
    std::string address = "cosmos16xkkyj97z7r83sx45xwk9uwq0mj0zszlf6c6mq";
    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<NodeCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient("https://stargate.cosmos.network"),
            COSMOS,
            std::make_shared<DynamicObject>()
    );

    auto transactions = ::wait(explorer->getTransactions(DEFAULT_ADDRESS, "recipient"));
    bool foundTx = false;
    for (const auto& tx : transactions) {
        if (tx.hash == "A57D7FD9615739D0F07F34FCFD352441B939C094F621E49C562A664A02650087") {
            foundTx = true;
            ASSERT_EQ(tx.block.getValue().height, 174362);
            ASSERT_EQ(tx.block.getValue().hash, "B69ACA3986E7FA52671FA5FBB2B81126E6E35C6D4A1026D24C31AA24C7D0781D");
            ASSERT_EQ(tx.logs.size(), 1);
            ASSERT_EQ(tx.logs.front().log, "");
            ASSERT_EQ(tx.logs.front().success, true);
            ASSERT_EQ(tx.messages.size(), 1);
            ASSERT_EQ(tx.messages.front().recipient, "cosmos16xkkyj97z7r83sx45xwk9uwq0mj0zszlf6c6mq");
            ASSERT_EQ(tx.messages.front().sender, "cosmos1pvnsselytw4zp9tym6a8m3ym88snezmezgx2rn");
            ASSERT_EQ(tx.messages.front().amount.toInt(), 1123000000);
            ASSERT_EQ(tx.messages.front().type, "cosmos-sdk/MsgSend");
            ASSERT_EQ(tx.messages.front().fees.toInt(), 969000);
            ASSERT_EQ(tx.gasLimit.toInt(), 38731);
            ASSERT_EQ(tx.gasUsed->toInt(), 29354);
            ASSERT_EQ(tx.memo, "(Sent via Lunie)");
            break;
        }
    }
    ASSERT_TRUE(foundTx);
    ASSERT_TRUE(transactions.size() >= 3);
}


TEST_F(CosmosLikeWalletSynchronization, GeturrentBlockWithExplorer) {
    std::string address = "cosmos16xkkyj97z7r83sx45xwk9uwq0mj0zszlf6c6mq";
    auto context = this->dispatcher->getSerialExecutionContext("context");
    auto pool = this->newDefaultPool();

    auto explorer = std::make_shared<NodeCosmosLikeBlockchainExplorer>(
            pool->getDispatcher()->getSerialExecutionContext("explorer"),
            pool->getHttpClient("https://stargate.cosmos.network"),
            COSMOS,
            std::make_shared<DynamicObject>()
    );

    auto block = ::wait(explorer->getCurrentBlock());
    EXPECT_TRUE(block->hash.size() > 0);
    EXPECT_TRUE(block->height > 0);
}

TEST_F(CosmosLikeWalletSynchronization, MediumXpubSynchronization) {
    auto pubKeyBech32 = "cosmospub1addwnpepqtztanmggwrgm92kafpagegck5dp8jc6frxkcpdzrspfafprrlx7gmvhdq6";
    auto pubKey = CosmosLikeExtendedPublicKey::fromBech32(ledger::core::currencies::COSMOS, pubKeyBech32, Option<std::string>("44'/118'/0'"))->derivePublicKey("");
    auto pubKeyStr = hex::toString(pubKey);
    api::AccountCreationInfo COSMOS_KEYS_INFO(
            0, {"main"}, {"44'/118'/0'"},
            {pubKey},
            {hex::toByteArray("b4f8427e7e19f284dfe7b99f107c55d00b3eae56df9569f0c4d56722742a5d71")} //TODO: fake value for now, replace with real value
    );
    auto pool = newDefaultPool();
    {
        auto configuration = DynamicObject::newInstance();
        configuration->putString(api::Configuration::KEYCHAIN_DERIVATION_SCHEME,
                                 "44'/<coin_type>'/<account>'/<node>/<address>");
        auto wallet = wait(pool->createWallet("e847815f-488a-4301-b67c-378a5e9c8a61", "cosmos", configuration));
        std::set<std::string> emittedOperations;
        {
            auto nextIndex = wait(wallet->getNextAccountIndex());
            EXPECT_EQ(nextIndex, 0);

            auto account = createCosmosLikeAccount(wallet, nextIndex, COSMOS_KEYS_INFO);

            auto receiver = make_receiver([&](const std::shared_ptr<api::Event> &event) {
                if (event->getCode() == api::EventCode::NEW_OPERATION) {
                    auto uid = event->getPayload()->getString(
                            api::Account::EV_NEW_OP_UID).value();
                    EXPECT_EQ(emittedOperations.find(uid), emittedOperations.end());
                }
            });

            pool->getEventBus()->subscribe(dispatcher->getMainExecutionContext(), receiver);

            receiver.reset();
            receiver = make_receiver([=](const std::shared_ptr<api::Event> &event) {
                fmt::print("Received event {}\n", api::to_string(event->getCode()));
                if (event->getCode() == api::EventCode::SYNCHRONIZATION_STARTED)
                    return;
                EXPECT_NE(event->getCode(), api::EventCode::SYNCHRONIZATION_FAILED);
                EXPECT_EQ(event->getCode(),
                          api::EventCode::SYNCHRONIZATION_SUCCEED);

                auto balance = wait(account->getBalance());
                std::cout << "Balance: " << balance->toString() << std::endl;
                auto txBuilder = std::dynamic_pointer_cast<CosmosLikeTransactionBuilder>(account->buildTransaction());
                dispatcher->stop();
            });

            auto restoreKey = account->getRestoreKey();
            account->synchronize()->subscribe(dispatcher->getMainExecutionContext(), receiver);

            dispatcher->waitUntilStopped();

            auto ops = wait(
                    std::dynamic_pointer_cast<OperationQuery>(account->queryOperations()->complete())->execute());
            std::cout << "Ops: " << ops.size() << std::endl;

            auto block = wait(account->getLastBlock());
            auto blockHash = block.blockHash;

        }
    }
}
