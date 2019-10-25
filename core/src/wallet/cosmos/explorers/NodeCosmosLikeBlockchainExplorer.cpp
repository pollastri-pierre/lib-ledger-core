/*
 *
 * NodeCosmosLikeBlockchainExplorer
 *
 * Created by El Khalil Bellakrid on 14/06/2019.
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


#include "NodeCosmosLikeBlockchainExplorer.h"
#include <api/CosmosConfigurationDefaults.hpp>
#include <api/Configuration.hpp>
#include <rapidjson/document.h>
namespace ledger {
    namespace core {
        NodeCosmosLikeBlockchainExplorer::NodeCosmosLikeBlockchainExplorer(
                const std::shared_ptr<api::ExecutionContext> &context,
                const std::shared_ptr<HttpClient> &http,
                const api::CosmosLikeNetworkParameters &parameters,
                const std::shared_ptr<api::DynamicObject> &configuration) :
                DedicatedContext(context),
                CosmosLikeBlockchainExplorer(configuration, {api::Configuration::BLOCKCHAIN_EXPLORER_API_ENDPOINT}) {
            _http = http;
            _parameters = parameters;
        }


        Future<std::shared_ptr<BigInt>>
        NodeCosmosLikeBlockchainExplorer::getBalance(const std::vector<CosmosLikeKeychain::Address> &addresses) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<std::shared_ptr<BigInt>>
        NodeCosmosLikeBlockchainExplorer::getEstimatedGasLimit(const std::shared_ptr<api::CosmosLikeTransaction> &transaction) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<String>
        NodeCosmosLikeBlockchainExplorer::pushLedgerApiTransaction(const std::vector<uint8_t> &transaction) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<void *> NodeCosmosLikeBlockchainExplorer::startSession() {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<Unit> NodeCosmosLikeBlockchainExplorer::killSession(void *session) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<Bytes> NodeCosmosLikeBlockchainExplorer::getRawTransaction(const String &transactionHash) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<String> NodeCosmosLikeBlockchainExplorer::pushTransaction(const std::vector<uint8_t> &transaction) {
            return pushLedgerApiTransaction(transaction);
        }

        FuturePtr<CosmosLikeBlockchainExplorer::TransactionsBulk>
        NodeCosmosLikeBlockchainExplorer::getTransactions(const std::vector<std::string> &addresses,
                                                          Option<std::string> fromBlockHash,
                                                          Option<void *> session) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        FuturePtr<Block> NodeCosmosLikeBlockchainExplorer::getCurrentBlock() const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        FuturePtr<CosmosLikeBlockchainExplorerTransaction>
        NodeCosmosLikeBlockchainExplorer::getTransactionByHash(const String &transactionHash) const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        Future<int64_t> NodeCosmosLikeBlockchainExplorer::getTimestamp() const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        std::shared_ptr<api::ExecutionContext> NodeCosmosLikeBlockchainExplorer::getExplorerContext() const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        api::CosmosLikeNetworkParameters NodeCosmosLikeBlockchainExplorer::getNetworkParameters() const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }

        std::string NodeCosmosLikeBlockchainExplorer::getExplorerVersion() const {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }


        Future<std::shared_ptr<BigInt>>
        NodeCosmosLikeBlockchainExplorer::getAccountInfo(const std::string &address,
                                                         const std::string &key) {
            throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING, "Not implemented");
        }
    }
}