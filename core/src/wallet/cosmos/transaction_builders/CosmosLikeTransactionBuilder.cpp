/*
 *
 * CosmosLikeTransactionBuilder
 *
 * Created by El Khalil Bellakrid on  14/06/2019.
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

#include "CosmosLikeTransactionBuilder.h"
#include <math/BigInt.h>
#include <api/CosmosLikeTransactionCallback.hpp>
#include <wallet/cosmos/api_impl/CosmosLikeTransactionApi.h>
#include <bytes/BytesReader.h>
#include <wallet/currencies.hpp>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
using namespace rapidjson;
namespace ledger {
    namespace core {
        CosmosLikeTransactionBuilder::CosmosLikeTransactionBuilder(
                const std::shared_ptr<api::ExecutionContext> &context,
                const api::Currency &currency,
                const std::shared_ptr<CosmosLikeBlockchainExplorer> &explorer,
                const std::shared_ptr<spdlog::logger> &logger,
                const CosmosLikeTransactionBuildFunction &buildFunction) {
            _context = context;
            _currency = currency;
            _explorer = explorer;
            _build = buildFunction;
            _logger = logger;
            _request.wipe = false;
        }

        CosmosLikeTransactionBuilder::CosmosLikeTransactionBuilder(const CosmosLikeTransactionBuilder &cpy) {
            _currency = cpy._currency;
            _build = cpy._build;
            _request = cpy._request;
            _context = cpy._context;
            _logger = cpy._logger;
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder>
        CosmosLikeTransactionBuilder::sendToAddress(const std::shared_ptr<api::Amount> &amount,
                                                    const std::string &address) {
            _request.value = std::make_shared<BigInt>(amount->toString());
            _request.toAddress = address;
            return shared_from_this();
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder>
        CosmosLikeTransactionBuilder::wipeToAddress(const std::string &address) {
            _request.toAddress = address;
            _request.wipe = true;
            return shared_from_this();
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder>
        CosmosLikeTransactionBuilder::setGasPrice(const std::shared_ptr<api::Amount> & gasPrice) {
            _request.gasPrice = std::make_shared<BigInt>(gasPrice->toString());
            return shared_from_this();
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder>
        CosmosLikeTransactionBuilder::setGasLimit(const std::shared_ptr<api::Amount> & gasLimit) {
            _request.gasLimit = std::make_shared<BigInt>(gasLimit->toString());
            return shared_from_this();
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder>
        CosmosLikeTransactionBuilder::setGasAdjustment(double gasAdjustment) {
            _request.gasAdjustment = gasAdjustment;
            return shared_from_this();
        }

        void CosmosLikeTransactionBuilder::build(const std::shared_ptr<api::CosmosLikeTransactionCallback> &callback) {
            build().callback(_context, callback);
        }

        Future<std::shared_ptr<api::CosmosLikeTransaction>> CosmosLikeTransactionBuilder::build() {
            return _build(_request, _explorer);
        }

        std::shared_ptr<api::CosmosLikeTransactionBuilder> CosmosLikeTransactionBuilder::clone() {
            return std::make_shared<CosmosLikeTransactionBuilder>(*this);
        }

        void CosmosLikeTransactionBuilder::reset() {
            _request = CosmosLikeTransactionBuildRequest();
        }

        std::shared_ptr<api::CosmosLikeTransaction>
        api::CosmosLikeTransactionBuilder::parseRawUnsignedTransaction(const api::Currency &currency,
                                                                       const std::string &rawTransaction) {
            return ::ledger::core::CosmosLikeTransactionBuilder::parseRawTransaction(currency, rawTransaction, false);
        }

        std::shared_ptr<api::CosmosLikeTransaction>
        api::CosmosLikeTransactionBuilder::parseRawSignedTransaction(const api::Currency &currency,
                                                                     const std::string &rawTransaction) {
            return ::ledger::core::CosmosLikeTransactionBuilder::parseRawTransaction(currency, rawTransaction, true);
        }

        std::shared_ptr<api::CosmosLikeTransaction>
        CosmosLikeTransactionBuilder::parseRawTransaction(const api::Currency &currency,
                                                          const std::string &rawTransaction,
                                                          bool isSigned) {
            auto tx = std::make_shared<CosmosLikeTransactionApi>(currency);
            Document document;
            document.Parse(rawTransaction.c_str());

            using Object = GenericValue<rapidjson::UTF8<char>, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>>::Object;
            auto getString = [] (const Object &object, const char *fieldName) {
                if (!object[fieldName].IsString()) {
                    throw Exception(api::ErrorCode::INVALID_ARGUMENT, fmt::format("Error while getting {} from rawTransaction", fieldName));
                }
                return object[fieldName].GetString();
            };

            auto getAmount = [=] (const Object &object) -> Amount {
                auto denom = getString(object, "denom");
                auto amount = getString(object, "amount");

                auto unit = std::find_if(currency.units.begin(), currency.units.end(), [&] (const api::CurrencyUnit &unit) {
                    return unit.name == denom;
                });
                if (unit == currency.units.end()) {
                    throw Exception(api::ErrorCode::INVALID_ARGUMENT, "Unknown unit while parsing transaction");
                }
                //TODO: Fix Amount::toUnit
                return Amount(currency, 0, BigInt(amount) * BigInt(10).pow(static_cast<unsigned short>((*unit).numberOfDecimal)));
            };

            tx->setAccountNumber(getString(document.GetObject(), "account_number"));
            tx->setMemo(getString(document.GetObject(), "memo"));
            tx->setSequence(getString(document.GetObject(), "sequence"));

            //Get fees
            if (document["fee"].IsObject()) {
                auto feeObject = document["fee"].GetObject();
                //Gas Limit
                auto gasLimit = std::make_shared<BigInt>(getString(feeObject, "gas"));
                tx->setGasLimit(gasLimit);

                //TODO: gas adjustment ?

                //Gas Price
                if (feeObject["amount"].IsArray() && feeObject["amount"].GetArray()[0].IsObject()) {
                    auto amountObject = feeObject["amount"].GetArray()[0].GetObject();
                    tx->setGasPrice(std::make_shared<BigInt>(BigInt(getAmount(amountObject).toString()) / *gasLimit));
                }
            }

            // Msgs object
            //TODO: handle multiple messages
            if (document["msgs"].IsArray() && document["msgs"].GetArray()[0].IsObject()) {
                auto msgs = document["msgs"].GetArray()[0].GetObject();
                if (msgs["value"].IsObject()) {
                    auto msgsValue = msgs["value"].GetObject();
                    // Amount
                    if (msgsValue["amount"].IsObject()) {
                        tx->setValue(std::make_shared<BigInt>(getAmount(msgsValue["amount"].GetObject()).toString()));
                    }

                    // Sender
                    tx->setSender(CosmosLikeAddress::fromBech32(getString(msgsValue, "from"), currency));

                    // Receiver
                    tx->setReceiver(CosmosLikeAddress::fromBech32(getString(msgsValue, "to"), currency));
                }
            }
            return tx;
        }
    }
}
