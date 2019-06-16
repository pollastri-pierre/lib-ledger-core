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
#include "api/rpcs_parsers.hpp"
#include <collections/collections.hpp>

// TODO COSMOS Compute gas price

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

        // TODO COSMOS Get curreny name from currency object

        FuturePtr<Block> NodeCosmosLikeBlockchainExplorer::getCurrentBlock() const {
            auto params = _parameters;
            return _http->GET(fmt::format("/blocks/latest")).json(true)
                    .map<std::shared_ptr<Block>>(getContext(),
                            [=] (const HttpRequest::JsonResult& response) {
                        auto result = std::make_shared<Block>();
                        const auto& document = std::get<1>(response)->GetObject();
                        rpcs_parsers::parseBlock(document, "cosmos", *result);
                        return result;
                    });
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

        Future<CosmosLikeBlockchainExplorerAccount>  NodeCosmosLikeBlockchainExplorer::getAccount(const std::string& address) {
            return _http->GET(fmt::format("/auth/accounts/{}", address)).json(true)
            .map<CosmosLikeBlockchainExplorerAccount>(getContext(),
                    [] (const HttpRequest::JsonResult& response) {
                // TODO COSMOS Maybe do some type checking here

                const auto& document = *std::get<1>(response);
                CosmosLikeBlockchainExplorerAccount result;
                rpcs_parsers::parseAccount(document.GetObject(), result);
                return result;
            });
        }

        Future<std::list<CosmosLikeBlockchainExplorerTransaction>> NodeCosmosLikeBlockchainExplorer::
        getTransactions(const std::string &address, const std::string& filter) {
            auto self = shared_from_this();
            return _http->GET(fmt::format("/txs?{}={}", filter, address)).json(true)
            .map<std::list<CosmosLikeBlockchainExplorerTransaction>>(getContext(),
                    [] (const HttpRequest::JsonResult& response) {
                std::list<CosmosLikeBlockchainExplorerTransaction> result;
                const auto& document = std::get<1>(response)->GetArray();

                for (const auto& item : document) {
                    CosmosLikeBlockchainExplorerTransaction tx;
                    rpcs_parsers::parseTransaction(item.GetObject(), tx);
                    result.emplace_back(tx);
                }

                return result;
            }).flatMap<std::list<CosmosLikeBlockchainExplorerTransaction>>(getContext(), [=] (const std::list<CosmosLikeBlockchainExplorerTransaction>& txs) {
                return self->fillBlocks(txs);
            });
        }

        Future<std::list<CosmosLikeBlockchainExplorerTransaction>> NodeCosmosLikeBlockchainExplorer::fillBlocks(const std::list<CosmosLikeBlockchainExplorerTransaction>& txs) {
            auto self = shared_from_this();
            auto context = getContext();
            auto params = self->_parameters;
            if (txs.empty())
                return Future<std::list<CosmosLikeBlockchainExplorerTransaction>>::successful({});
            else {
                auto head = txs.front();
                std::list<CosmosLikeBlockchainExplorerTransaction> tail(++txs.begin(), txs.end());
                if (head.block.isEmpty()) {
                    return self->fillBlocks(tail).map<std::list<CosmosLikeBlockchainExplorerTransaction>>(context, [=] (const std::list<CosmosLikeBlockchainExplorerTransaction>& res) {
                       return list::concat({head}, res);
                    });
                } else
                    return _http->GET(fmt::format("/blocks/{}", head.block.getValue().height)).json(true).flatMap<std::list<CosmosLikeBlockchainExplorerTransaction>>(context, [=] (const HttpRequest::JsonResult& response) {
                        auto result = std::make_shared<Block>();
                        const auto& document = std::get<1>(response)->GetObject();
                        rpcs_parsers::parseBlock(document, "cosmos", *result);
                        CosmosLikeBlockchainExplorerTransaction newHead = head;
                        newHead.block = Option<Block>(*result);
                        return self->fillBlocks(tail).map<std::list<CosmosLikeBlockchainExplorerTransaction>>(context, [=] (const std::list<CosmosLikeBlockchainExplorerTransaction>& res) {
                            return list::concat({newHead}, res);
                        });
                    });
            }

        }

        Future<std::list<CosmosLikeBlockchainExplorerTransaction>>
        NodeCosmosLikeBlockchainExplorer::getTransactions(const std::string &address,
                                                          const std::list<std::string> &filters) {
            auto self = shared_from_this();
            auto context = getContext();
            if (filters.empty()) {
                return Future<std::list<CosmosLikeBlockchainExplorerTransaction>>::successful({});
            } else {
                return getTransactions(address, filters.front())
                .flatMap<std::list<CosmosLikeBlockchainExplorerTransaction>>(context, [=] (const std::list<CosmosLikeBlockchainExplorerTransaction> mTxs) {
                    auto tail = std::list<std::string>(++filters.begin(), filters.end());
                    return self->getTransactions(address, tail).map<std::list<CosmosLikeBlockchainExplorerTransaction>>(context, [=] (const std::list<CosmosLikeBlockchainExplorerTransaction> txs) {
                        return list::concat(mTxs, txs);
                    });
                });
            }
        }

        Future<std::list<CosmosLikeBlockchainExplorerTransaction>>
        NodeCosmosLikeBlockchainExplorer::getTransactions(const std::string &address) {
            return getTransactions(address, std::list<std::string>({"recipient", "sender"}));
        }

    }
}
