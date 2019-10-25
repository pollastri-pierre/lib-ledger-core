/*
 *
 * rpcs_parsers.hpp
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

#ifndef LEDGER_CORE_RPCS_PARSERS_HPP
#define LEDGER_CORE_RPCS_PARSERS_HPP

#include "../CosmosLikeBlockchainExplorer.h"
#include <rapidjson/document.h>
#include <utils/Option.hpp>
#include <wallet/currencies.hpp>

namespace ledger {
    namespace core {
        namespace rpcs_parsers {
            template <class T>
            void parseAccount(const T& accountNode,
                    CosmosLikeBlockchainExplorerAccount& account) {
                const auto& node = accountNode["value"].GetObject();
                account.accountNumber = node["account_number"].GetString();
                account.sequence = node["sequence"].GetString();
                account.address = node["address"].GetString();
                account.type = accountNode["type"].GetString();
                const auto& balances = node["coins"].GetArray();
                for (const auto& balance : balances) {
                    auto amount = BigInt::fromString(balance.GetObject()["amount"].GetString());
                    auto denom = balance.GetObject()["denom"].GetString();

                    auto unit = std::find_if(currencies::COSMOS.units.begin(), currencies::COSMOS.units.end(), [&] (const api::CurrencyUnit &unit) {
                        return unit.name == denom;
                    });
                    if (unit == currencies::COSMOS.units.end()) {
                        throw Exception(api::ErrorCode::INVALID_ARGUMENT, "Unknown unit while parsing transaction");
                    }
                    //TODO: Fix Amount::toUnit and use right unit
                    account.balances.emplace_front(BigInt(amount) * BigInt(10).pow(static_cast<unsigned short>((*unit).numberOfDecimal)));
                }
            }

            template <class T>
            void parseTransaction(const T& node,
                    CosmosLikeBlockchainExplorerTransaction& transaction) {
                transaction.hash = node["txhash"].GetString();
                if (node.HasMember("height")) {
                    Block block;
                    block.height = BigInt::fromString(node["height"].GetString()).toUint64();
                    //TODO: set rest of block data
                    transaction.block = block;
                }
                if (node.HasMember("memo"))
                    transaction.memo = node["memo"].GetString();
                if (node.HasMember("gas_used"))
                    transaction.gasUsed = Option<BigInt>(BigInt::fromString(node["gas_used"].GetString()));
                for (const auto& lNode : node["logs"].GetArray()) {
                    CosmosLikeBlockchainExplorerLog log;
                    log.success = lNode["success"].GetBool();
                    log.log = lNode["log"].GetString();
                    log.messageIndex = BigInt::fromString(lNode["msg_index"].GetString()).toInt();
                    transaction.logs.emplace_back(log);
                }

            }
        };
    }
}

#endif //LEDGER_CORE_RPCS_PARSERS_HPP
