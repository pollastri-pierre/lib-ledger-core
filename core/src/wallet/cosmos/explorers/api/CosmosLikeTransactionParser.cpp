/*
 *
 * CosmosLikeTransactionParser
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


#include <wallet/currencies.hpp>
#include "CosmosLikeTransactionParser.h"

#define PROXY_PARSE(method, ...)                                    \
 auto& currentObject = _hierarchy.top();                            \
 if (currentObject == "block") {                                    \
    return _blockParser.method(__VA_ARGS__);                        \
 } else                                                             \

namespace ledger {
    namespace core {

        bool CosmosLikeTransactionParser::Key(const rapidjson::Reader::Ch *str, rapidjson::SizeType length, bool copy) {
            PROXY_PARSE(Key, str, length, copy) {
                return true;
            }
        }

        bool CosmosLikeTransactionParser::StartObject() {
            if (_arrayDepth == 0) {
                _hierarchy.push(_lastKey);
            }
            return true;
        }

        bool CosmosLikeTransactionParser::EndObject(rapidjson::SizeType memberCount) {
            auto &currentObject = _hierarchy.top();
            if (_arrayDepth == 0) {
                _hierarchy.pop();
            }
            return true;
        }

        bool CosmosLikeTransactionParser::StartArray() {
            if (_arrayDepth == 0) {
                _hierarchy.push(_lastKey);
            }
            _arrayDepth += 1;
            return true;
        }

        bool CosmosLikeTransactionParser::EndArray(rapidjson::SizeType elementCount) {
            _arrayDepth -= 1;
            if (_arrayDepth == 0) {
                _hierarchy.pop();
            }
            return true;
        }

        bool CosmosLikeTransactionParser::Null() {
            PROXY_PARSE(Null) {
                return true;
            }
        }

        bool CosmosLikeTransactionParser::Bool(bool b) {
            PROXY_PARSE(Bool, b) {
                return true;
            }
        }

        bool CosmosLikeTransactionParser::Int(int i) {
            return Uint64(i);
        }

        bool CosmosLikeTransactionParser::Uint(unsigned i) {
            return Uint64(i);
        }

        bool CosmosLikeTransactionParser::Int64(int64_t i) {
            return Uint64(i);
        }

        bool CosmosLikeTransactionParser::Uint64(uint64_t i) {
            PROXY_PARSE(Uint64, i) {
                return true;
            }
        }

        bool CosmosLikeTransactionParser::Double(double d) {
            PROXY_PARSE(Double, d) {
                return true;
            }
        }

        bool CosmosLikeTransactionParser::RawNumber(const rapidjson::Reader::Ch *str, rapidjson::SizeType length,
                                                    bool copy) {
            PROXY_PARSE(RawNumber, str, length, copy) {
                return true;
            }
        }

        bool
        CosmosLikeTransactionParser::String(const rapidjson::Reader::Ch *str, rapidjson::SizeType length, bool copy) {
            PROXY_PARSE(String, str, length, copy) {
                std::string value(str, length);
                return true;
            }
        }

        CosmosLikeTransactionParser::CosmosLikeTransactionParser(std::string &lastKey) :
                _lastKey(lastKey), _blockParser(lastKey) {
            _arrayDepth = 0;
        }

        void CosmosLikeTransactionParser::init(CosmosLikeBlockchainExplorerTransaction *transaction) {
            _transaction = transaction;
        }

    }
}
