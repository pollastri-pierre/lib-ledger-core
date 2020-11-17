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
#include "FakeHttpClient.hpp"
#include <boost/algorithm/string/join.hpp>

using namespace ledger::core;
using namespace::std;

struct BitcoinReorg : public BaseFixture {
    const string endpoint="http://localhost:20000";
    const string invalid_block="696b84988e502eb766ba1ef865ee36d542c2ebe030fd434c5ae94fbcec58e8df";
    const string block_response_init=R"({"hash":"0x3ab9962c5a557ac0a9f20cae73c470f86e624ddb0bb66be088f9f5eb357005ec","height":302,"time":"2020-11-15T19:02:45Z","txs":["0xfffdea89a1d28b2a768bc8ac89778a35246c2fcb6d028e7fa7a9d8585e09a13e","0x23d0e7c76e692eabd4c8bfe7c8a453f2c94b4fdc7afbebfcfb66aa5c412ab2c6"]})";
    const string block_response_before_reorg=R"({"hash":"0x696b84988e502eb766ba1ef865ee36d542c2ebe030fd434c5ae94fbcec58e8df","height":503,"time":"2020-11-16T10:26:57Z","txs":["0x4cd159b24d8ef1884cf72a9760cd54125de8498c05f967bc416a907d89b0f3bb","0xeec9ee8abe1154ea09ceda4fa006b4acee9cc503b72d705d4c0b575fb78ea1b3"]})";
    const string block_response_after_reorg=R"({"hash":"0x118f6a4ce9b2f58b5baf4e2789c810a2020638966a72669dbd5265e4f7dbfb9a","height":504,"time":"2020-11-16T10:32:02Z","txs":["0x289021c4dbfda5b3d74388544dd21600d7dc6c989d8738311a679a19fe6e22b9"]})";
    const string no_tx_response=R"({"truncated":false,"txs":[]})";
    const string tx_response_before_reorg=R"({"truncated":false,"txs":[{"id":"bfe03cb97647b8d9a2146bc0f7c85a347c6152e382d343d54168ddd74503b226","hash":"bfe03cb97647b8d9a2146bc0f7c85a347c6152e382d343d54168ddd74503b226","received_at":"2020-11-16T10:26:41Z","lock_time":402,"fees":4440,"inputs":[{"output_hash":"ef04b77dcc7d0d6c472658953f3f8f6c80f41c16aac5a5ad248606c8460e9a2d","output_index":0,"input_index":0,"value":1250000000,"address":"mjTkW3DjgyZck4KbiRusZsqTgaYTxdSz6z","script_signature":"4730440220036c1b47ea1de2526fb7ad6d1b197748721c4e781d0dc77bdcc5d80e03cb68fa022013f7898b2be492b74252a566c21e609257b35df3fd36e49947350f322807a9b301210227d85ba011276cf25b51df6a188b75e604b38770a462b2d0e9fb2fc839ef5d3f","txinwitness":[],"sequence":4294967294}],"outputs":[{"output_index":0,"value":249995560,"address":"bcrt1qlgrph7tpj6lrjfgz870h4kpzgjlxw4g6ptwyh8","script_hex":"0014fa061bf96196be3925023f9f7ad82244be67551a"},{"output_index":1,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"}],"block":{"hash":"43e7556e67b0f1553e7d5d8684031a9b1c30c286a03337fa8f923d1be27c8463","height":403,"time":"2020-11-16T10:26:41Z"},"confirmations":100},{"id":"ca57e658eb3feb4ba015ab9e6184e67610b2a30a6fcb42abb18219b48cd3af7d","hash":"ca57e658eb3feb4ba015ab9e6184e67610b2a30a6fcb42abb18219b48cd3af7d","received_at":"2020-11-16T10:26:41Z","lock_time":402,"fees":4440,"inputs":[{"output_hash":"59ca8070659238ef11dee41d92a0069f5eb836e2839e75ee8b16557a6444bbe0","output_index":0,"input_index":0,"value":1250000000,"address":"mjTkW3DjgyZck4KbiRusZsqTgaYTxdSz6z","script_signature":"4730440220720e5aa8b01090f796797a30d5e3688d3e090df0527d991e9ace4827661a2dca022043fa8f5bed15cf1b66d483a9842f1e02b25faccc2464febc61730883bce3102a01210227d85ba011276cf25b51df6a188b75e604b38770a462b2d0e9fb2fc839ef5d3f","txinwitness":[],"sequence":4294967294}],"outputs":[{"output_index":0,"value":249995560,"address":"bcrt1qqlrynypa84eautl6akg9gf3syfq5fk9zxjrwdp","script_hex":"001407c649903d3d73de2ffaed90542630224144d8a2"},{"output_index":1,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"}],"block":{"hash":"43e7556e67b0f1553e7d5d8684031a9b1c30c286a03337fa8f923d1be27c8463","height":403,"time":"2020-11-16T10:26:41Z"},"confirmations":100},{"id":"eec9ee8abe1154ea09ceda4fa006b4acee9cc503b72d705d4c0b575fb78ea1b3","hash":"eec9ee8abe1154ea09ceda4fa006b4acee9cc503b72d705d4c0b575fb78ea1b3","received_at":"2020-11-16T10:26:57Z","lock_time":502,"fees":2880,"inputs":[{"output_hash":"542e55841d0dc7a69e6b38d2a6cb7ce90b50dd6ea73d1ec66f1c11f95128b687","output_index":0,"input_index":0,"value":1250000000,"address":"bcrt1qsxt4sz9qxr56zqaxmt5y727g5ylsk27utwxty4","script_signature":"","txinwitness":["304402205e1dec8cad8c43d6fe7569578d60393a1df7fe510c39442d579ed8f0945fb3b0022060cdf789623fc1a7c08ab37bcec59f76899d5eee3fe2e9a561b4225da0a6763c01","02310cb8ea46ffae04de40fe15809bbe80f50e9a154b0fdbd8b4b997d0d14e2f23"],"sequence":4294967294}],"outputs":[{"output_index":0,"value":249997120,"address":"bcrt1q5phrg5d87pqtnwyanh5wl9zypkctq4yejgq0z0","script_hex":"0014a06e3451a7f040b9b89d9de8ef94440db0b05499"},{"output_index":1,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"}],"block":{"hash":"696b84988e502eb766ba1ef865ee36d542c2ebe030fd434c5ae94fbcec58e8df","height":503,"time":"2020-11-16T10:26:57Z"},"confirmations":0}]})";
    const string tx_response_after_reorg=R"({"truncated":false,"txs":[{"id":"bfe03cb97647b8d9a2146bc0f7c85a347c6152e382d343d54168ddd74503b226","hash":"bfe03cb97647b8d9a2146bc0f7c85a347c6152e382d343d54168ddd74503b226","received_at":"2020-11-16T14:08:54Z","lock_time":402,"fees":4440,"inputs":[{"output_hash":"ef04b77dcc7d0d6c472658953f3f8f6c80f41c16aac5a5ad248606c8460e9a2d","output_index":0,"input_index":0,"value":1250000000,"address":"mjTkW3DjgyZck4KbiRusZsqTgaYTxdSz6z","script_signature":"473044022061192055d2bc6e81b63aaa3d080e185fad9fc4adcd4703f3aa762929ffb1afe1022060552eb871d5945e9582e4bc2a2330e0d25dc318fc6175da555dd8ac6dba78cf01210227d85ba011276cf25b51df6a188b75e604b38770a462b2d0e9fb2fc839ef5d3f","txinwitness":[],"sequence":4294967294}],"outputs":[{"output_index":0,"value":249995560,"address":"bcrt1qlx8yenhyvqasfjc39hdjy5vvv7pr3l5mmyhqt0","script_hex":"0014f98e4ccee4603b04cb112ddb22518c678238fe9b"},{"output_index":1,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"}],"block":{"hash":"43e7556e67b0f1553e7d5d8684031a9b1c30c286a03337fa8f923d1be27c8463","height":403,"time":"2020-11-16T14:08:54Z"},"confirmations":101},{"id":"ca57e658eb3feb4ba015ab9e6184e67610b2a30a6fcb42abb18219b48cd3af7d","hash":"ca57e658eb3feb4ba015ab9e6184e67610b2a30a6fcb42abb18219b48cd3af7d","received_at":"2020-11-16T14:08:54Z","lock_time":402,"fees":4440,"inputs":[{"output_hash":"59ca8070659238ef11dee41d92a0069f5eb836e2839e75ee8b16557a6444bbe0","output_index":0,"input_index":0,"value":1250000000,"address":"mjTkW3DjgyZck4KbiRusZsqTgaYTxdSz6z","script_signature":"47304402205994e62595dd99dfc1095a3e397dba3cbd533244a0786cfe5ce077f123a4b3aa0220284eb2dbc9f5f26dd771477ad2f33f0a87ce0aa9b8a500527dd1bb6eb2eb775501210227d85ba011276cf25b51df6a188b75e604b38770a462b2d0e9fb2fc839ef5d3f","txinwitness":[],"sequence":4294967294}],"outputs":[{"output_index":0,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"},{"output_index":1,"value":249995560,"address":"bcrt1qgn6x03gge53qe63fuy8cczkaa88fv07x0hkvqc","script_hex":"001444f467c508cd220cea29e10f8c0adde9ce963fc6"}],"block":{"hash":"43e7556e67b0f1553e7d5d8684031a9b1c30c286a03337fa8f923d1be27c8463","height":403,"time":"2020-11-16T14:08:54Z"},"confirmations":101},{"id":"e5969464438cf7152d961a3898c39aa54a035dd68610acc79c2c8b3c971a222f","hash":"e5969464438cf7152d961a3898c39aa54a035dd68610acc79c2c8b3c971a222f","received_at":"2020-11-16T14:16:09Z","lock_time":502,"fees":2880,"inputs":[{"output_hash":"6d7e426aea7ce50ad405959887731858034793d12f0592148e903fd70fa1df7d","output_index":0,"input_index":0,"value":1250000000,"address":"bcrt1qnw2zvu9f9gzshzfnxwf7j2mht7h3yr2puptjp4","script_signature":"","txinwitness":["3044022016bd02c08c057446ea62536bb5a7921452cb8ed1966e41102b86f5752ef307d1022034d3f9621439678da4304c444bedeb201bedcd2b4fd471dceea945a84b4c8e6d01","02cf9cfca89f1ed502e6488391f223e8568e5ad1b6342805b199776d3189946b10"],"sequence":4294967294}],"outputs":[{"output_index":0,"value":249997120,"address":"bcrt1qkvk4zntne2yg7gpvw6prn5dyw8why4gyl0wyys","script_hex":"0014b32d514d73ca888f202c768239d1a471dd725504"},{"output_index":1,"value":1000000000,"address":"msj9HnRwynf6qwp2ubRQLDLMscYtFrwagG","script_hex":"76a91485efaded203a798edc46cd458f0714136f6d0acb88ac"}],"block":{"hash":"13a23f9f3cf0173c403d463bcc91b1098992eca74831a32f92200d7aada86d07","height":503,"time":"2020-11-16T14:16:09Z"},"confirmations":1}]})";
};

static string synchronize(const std::shared_ptr<BitcoinLikeAccount>& account) {
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
    return uv::wait(account->getBalance())->toString();
}

TEST_F(BitcoinReorg, RemoveBlock) {
    auto dispatcher = uv::createDispatcher();
    auto fakeHttp = std::make_shared<ledger::core::test::FakeHttpClient>();
    auto resolver = std::make_shared<NativePathResolver>(IntegrationEnvironment::getInstance()->getApplicationDirPath());
    auto printer = std::make_shared<CoutLogPrinter>(dispatcher->getMainExecutionContext());
    //auto http = std::make_shared<CppHttpLibClient>(dispatcher->getMainExecutionContext());
    auto rng = std::make_shared<OpenSSLRandomNumberGenerator>();
    auto backend = std::static_pointer_cast<DatabaseBackend>(DatabaseBackend::getSqlite3Backend());

    auto pool = WalletPool::newInstance(
            "reorg", "", fakeHttp, nullptr, resolver, printer, dispatcher, rng, backend,
            api::DynamicObject::newInstance(), nullptr, nullptr);

    auto configuration = api::DynamicObject::newInstance();
    configuration->putString(api::Configuration::BLOCKCHAIN_EXPLORER_API_ENDPOINT,endpoint);
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
    std::vector<string> address_batch0,address_batch1;
    for (auto address:uv::wait(account->getAddresses(0, 19)))
        address_batch0.emplace_back(address->toString());
    for (auto address:uv::wait(account->getAddresses(20, 39)))
        address_batch1.emplace_back(address->toString());
    string request_batch0=endpoint+"/blockchain/v3/btc_testnet/addresses/"+boost::algorithm::join(address_batch0, ",")+"/transactions?no_token=true";
    string request_batch1=endpoint+"/blockchain/v3/btc_testnet/addresses/"+boost::algorithm::join(address_batch1, ",")+"/transactions?no_token=true";
    fmt::print("Address: {}\n", address_batch0[0]);
    fakeHttp->setBehavior({
        {
            endpoint + "/blockchain/v3/btc_testnet/blocks/current" ,
            test::FakeUrlConnection::fromString(block_response_init)
        },
        {
            request_batch0,
            test::FakeUrlConnection::fromString(no_tx_response)
        },
        {
            request_batch1,
            test::FakeUrlConnection::fromString(no_tx_response)
        },
    });
    EXPECT_EQ(synchronize(account),"0");
    fmt::print("Send 30 BTC\n");
    fakeHttp->setBehavior({
        {
            endpoint + "/blockchain/v3/btc_testnet/blocks/current" ,
            test::FakeUrlConnection::fromString(block_response_before_reorg)
        },
        {
            request_batch0,
            test::FakeUrlConnection::fromString(tx_response_before_reorg)
        },
        {
            request_batch1,
            test::FakeUrlConnection::fromString(no_tx_response)
        },
    });
    EXPECT_EQ(synchronize(account),"3000000000");
    {
        int count;
        soci::session sql(pool->getDatabaseSessionPool()->getPool());
        sql << "select count(*) from blocks where hash= :hash", soci::into(count), soci::use(invalid_block);
        EXPECT_EQ(count, 1); // the invalid block exists before reorg
    }
    fmt::print("Reorg\n");
    fakeHttp->setBehavior({
        {
            endpoint + "/blockchain/v3/btc_testnet/blocks/current" ,
            test::FakeUrlConnection::fromString(block_response_after_reorg)
        },
        {
            request_batch0+"&block_hash=43e7556e67b0f1553e7d5d8684031a9b1c30c286a03337fa8f923d1be27c8463",
            test::FakeUrlConnection::fromString(tx_response_after_reorg)
        },
        {
            request_batch1,
            test::FakeUrlConnection::fromString(no_tx_response)
        },
    });
    EXPECT_EQ(synchronize(account),"3000000000");
    {
        int count;
        soci::session sql(pool->getDatabaseSessionPool()->getPool());
        sql << "select count(*) from blocks where hash= :hash", soci::into(count), soci::use(invalid_block);
        EXPECT_EQ(count, 0); // the invalid block has been removed after reorg
    }
}
