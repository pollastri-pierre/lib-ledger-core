/*
 *
 * CosmosLikeWebSocketNotification
 *
 * Created by El Khalil Bellakrid on 07/01/2019.
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


#ifndef LEDGER_CORE_COSMOSLIKEWEBSOCKETNOTIFICATION_H
#define LEDGER_CORE_COSMOSLIKEWEBSOCKETNOTIFICATION_H

#include <cstdio>
#include <cstdint>
#include <rapidjson/reader.h>
#include <stack>
#include <net/HttpClient.hpp>
#include <collections/collections.hpp>
#include "../CosmosLikeBlockchainExplorer.h"
#include "CosmosLikeBlockParser.h"
#include "CosmosLikeTransactionParser.h"
#include <wallet/common/explorers/api/AbstractWebSocketNotificationParser.h>


#define PROXY_PARSE_COSMOS_WS(method, ...)                                         \
 auto& currentObject = _currentObject;                                   \
 if (currentObject == "transaction") {                            \
    return getTransactionParser().method(__VA_ARGS__);                       \
 } else                                                                  \

namespace ledger {
    namespace core {
        class CosmosLikeWebSocketNotificationParser
                : public AbstractWebSocketNotificationParser<CosmosLikeBlockchainExplorerTransaction, CosmosLikeBlockchainExplorer::Block, CosmosLikeTransactionParser, CosmosLikeBlockParser> {
        public:


            explicit CosmosLikeWebSocketNotificationParser(std::string &lastKey) : _lastKey(lastKey),
                                                                                   _blockParser(lastKey),
                                                                                   _transactionParser(lastKey) {

            }

            bool Key(const rapidjson::Reader::Ch *str, rapidjson::SizeType length, bool copy) override {
                _lastKey = std::string(str, length);
                return AbstractWebSocketNotificationParser<CosmosLikeBlockchainExplorerTransaction,
                        CosmosLikeBlockchainExplorer::Block,
                        CosmosLikeTransactionParser,
                        CosmosLikeBlockParser>::Key(str, length, copy);
            }

            bool StartObject() {
                {
                    _depth += 1;
                    auto lastKey = getLastKey();
                }
                PROXY_PARSE_COSMOS_WS(StartObject) {
                    return true;
                }
            };

            bool RawNumber(const rapidjson::Reader::Ch *str, rapidjson::SizeType length,
                           bool copy) {
                PROXY_PARSE_COSMOS_WS(String, str, length, copy) {
                }
                return true;
            };

            bool
            String(const rapidjson::Reader::Ch *str, rapidjson::SizeType length, bool copy) {
                return true;
            };

            bool EndObject(rapidjson::SizeType memberCount) {
                return true;
            };

        protected:

            CosmosLikeTransactionParser &getTransactionParser() override {
                return _transactionParser;
            };

            CosmosLikeBlockParser &getBlockParser() override {
                return _blockParser;
            };

            std::string &getLastKey() override {
                return _lastKey;
            };

        private:
            std::string &_lastKey;
            CosmosLikeBlockParser _blockParser;
            CosmosLikeTransactionParser _transactionParser;
        };
    }
}


#endif //LEDGER_CORE_COSMOSLIKEWEBSOCKETNOTIFICATION_H
