/*
 *
 * CosmosLikeBlockchainExplorer
 *
 * Created by El Khalil Bellakrid on 14/06/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
BB *
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


#ifndef LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H
#define LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H


#include <string>

#include <api/DynamicObject.hpp>
#include <api/ExecutionContext.hpp>
#include <api/CosmosLikeNetworkParameters.hpp>
#include <api/CosmosLikeTransaction.hpp>
#include <async/DedicatedContext.hpp>
#include <collections/DynamicObject.hpp>
#include <math/BigInt.h>
#include <net/HttpClient.hpp>
#include <utils/ConfigurationMatchable.h>
#include <utils/Option.hpp>
#include <wallet/common/Block.h>
#include <wallet/common/explorers/AbstractBlockchainExplorer.h>
#include <wallet/cosmos/keychains/CosmosLikeKeychain.h>

namespace ledger {
    namespace core {

        struct CosmosLikeBlockchainExplorerAmountField {
            BigInt value;
            std::string denom;
        };

        struct CosmosLikeBlockchainExplorerFee {
            std::list<CosmosLikeBlockchainExplorerAmountField> amount;
            BigInt gas;
        };

        struct CosmosLikeBlockchainExplorerMessage {
            std::string type;
            std::string sender;
            std::string recipient;
            CosmosLikeBlockchainExplorerAmountField amount;
        };

        struct CosmosLikeBlockchainExplorerLog {
            int32_t messageIndex;
            bool success;
            std::string log;
        };

        struct CosmosLikeBlockchainExplorerTransaction {
            std::string hash;
            Option<BigInt> height;
            BigInt gasLimit;
            Option<BigInt> gasUsed;
            BigInt gasPrice; // TODO COSMOS Hackathon shortcut, the gas price seems to be set per messages
            std::chrono::system_clock::time_point timestamp;
            std::list<CosmosLikeBlockchainExplorerMessage> messages;
            CosmosLikeBlockchainExplorerFee fee;
            std::string memo;
            std::list<CosmosLikeBlockchainExplorerLog> logs;
        };

        struct CosmosLikeBlockchainExplorerAccount {
            std::string type;
            std::string address;
            std::list<CosmosLikeBlockchainExplorerAmountField> balances;
            std::string accountNumber;
            std::string sequence;
        };

        class CosmosLikeBlockchainExplorer : public ConfigurationMatchable,
                                             public AbstractBlockchainExplorer<CosmosLikeBlockchainExplorerTransaction> {
        public:
            typedef ledger::core::Block Block;

            CosmosLikeBlockchainExplorer(const std::shared_ptr<ledger::core::api::DynamicObject> &configuration,
                                         const std::vector<std::string> &matchableKeys);

            virtual Future<std::shared_ptr<BigInt>>
            getBalance(const std::vector<CosmosLikeKeychain::Address> &addresses) = 0;

            virtual Future<std::shared_ptr<BigInt>>
            getEstimatedGasLimit(const std::shared_ptr<api::CosmosLikeTransaction> &transaction) = 0;

            virtual Future<CosmosLikeBlockchainExplorerAccount> getAccount(const std::string& address) = 0;
            virtual Future<std::list<CosmosLikeBlockchainExplorerTransaction>> getTransactions(const std::string &address, const std::string& filter) = 0;

        };
    }
}


#endif //LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H
