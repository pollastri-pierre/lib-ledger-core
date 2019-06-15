/*
 *
 * CosmosLikeTransactionApi
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


#include "CosmosLikeTransactionApi.h"
#include <wallet/common/Amount.h>
#include <wallet/common/AbstractAccount.hpp>
#include <wallet/common/AbstractWallet.hpp>
#include <cosmos/CosmosLikeAddress.h>
#include <bytes/BytesWriter.h>
#include <bytes/BytesReader.h>
#include <utils/hex.h>
#include <api_impl/BigIntImpl.hpp>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>
using namespace rapidjson;
namespace ledger {
    namespace core {

        CosmosLikeTransactionApi::CosmosLikeTransactionApi(const api::Currency &currency) {
            _currency = currency;
        }

        CosmosLikeTransactionApi::CosmosLikeTransactionApi(const std::shared_ptr<OperationApi> &operation) {
            auto &tx = operation->getBackend().cosmosTransaction.getValue();
            _time = tx.timestamp;

            // TODO COSMOS Retrieve a block (the model only has an optional height)
            _block = nullptr;

            _hash = tx.hash;

            _currency = operation->getAccount()->getWallet()->getCurrency();

            _gasPrice = std::make_shared<Amount>(_currency, 0, tx.gasPrice);
            _gasLimit = std::make_shared<Amount>(_currency, 0, tx.gasLimit);

            // TODO COSMOS Hack!!! Normally we should have multiple messages here and not a sender and recipient

            _value = std::make_shared<Amount>(_currency, 0, tx.messages.front().amount.value);

            _receiver = CosmosLikeAddress::fromBech32(tx.messages.front().recipient, _currency);
            _sender = CosmosLikeAddress::fromBech32(tx.messages.front().sender, _currency);

        }

        std::string CosmosLikeTransactionApi::getHash() {
            return _hash;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getFees() {
            return std::make_shared<Amount>(_currency, 0, BigInt(_gasPrice->toString()) * BigInt(_gasLimit->toString()));
        }

        std::shared_ptr<api::CosmosLikeAddress> CosmosLikeTransactionApi::getReceiver() {
            return _receiver;
        }

        std::shared_ptr<api::CosmosLikeAddress> CosmosLikeTransactionApi::getSender() {
            return _sender;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getValue() {
            return _value;
        }

        std::chrono::system_clock::time_point CosmosLikeTransactionApi::getDate() {
            return _time;
        }

        std::vector<uint8_t> CosmosLikeTransactionApi::getSigningPubKey() {
            return _signingPubKey;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getGasLimit() {
            return _gasLimit;
        }

        std::shared_ptr<api::Amount> CosmosLikeTransactionApi::getGasPrice() {
            return _gasPrice;
        }

        double CosmosLikeTransactionApi::getGasAdjustment() {
            return _gasAdjustment;
        }

        void CosmosLikeTransactionApi::setSignature(const std::vector<uint8_t> &rSignature,
                                                    const std::vector<uint8_t> &sSignature) {
            _rSignature = rSignature;
            _sSignature = sSignature;
        }

        void CosmosLikeTransactionApi::setDERSignature(const std::vector<uint8_t> &signature) {
            BytesReader reader(signature);
            //DER prefix
            reader.readNextByte();
            //Total length
            reader.readNextVarInt();
            //Nb of elements for R
            reader.readNextByte();
            //R length
            auto rSize = reader.readNextVarInt();
            if (rSize > 0 && reader.peek() == 0x00) {
                reader.readNextByte();
                _rSignature = reader.read(rSize - 1);
            } else {
                _rSignature = reader.read(rSize);
            }
            //Nb of elements for S
            reader.readNextByte();
            //S length
            auto sSize = reader.readNextVarInt();
            if (sSize > 0 && reader.peek() == 0x00) {
                reader.readNextByte();
                _sSignature = reader.read(sSize - 1);
            } else {
                _sSignature = reader.read(sSize);
            }
        }

        std::string CosmosLikeTransactionApi::serialize() {
            Document document;
            document.SetObject();

            Document::AllocatorType& allocator = document.GetAllocator();

            Value vString(rapidjson::kStringType);
            vString.SetString(_accountNumber.c_str(), static_cast<rapidjson::SizeType>(_accountNumber.length()), allocator);
            document.AddMember("account_number", vString, allocator);

            auto chainID = _currency.cosmosLikeNetworkParameters.value().ChainId;
            vString.SetString(chainID.c_str(), static_cast<rapidjson::SizeType>(chainID.length()), allocator);
            document.AddMember("chain_id", vString, allocator);

            auto getAmountObject = [&] (const std::string &denom, const std::string &amount) {
                Value amountObject(kObjectType);
                Value vStringLocal(rapidjson::kStringType);
                vStringLocal.SetString(amount.c_str(), static_cast<rapidjson::SizeType>(amount.length()), allocator);
                amountObject.AddMember("amount", vStringLocal, allocator);
                vStringLocal.SetString(denom.c_str(), static_cast<rapidjson::SizeType>(denom.length()), allocator);
                amountObject.AddMember("denom", vStringLocal, allocator);
                return amountObject;
            };

            // Fees object
            auto fees = std::make_shared<BigInt>(BigInt(_gasPrice->toString()) * BigInt(_gasLimit->toString()));
            auto feeAmountObj = getAmountObject(_gasPrice->getUnit().name, fees->toString());
            Value feeArray(kArrayType);
            feeArray.PushBack(feeAmountObj, allocator);
            Value feeAmountObject(kObjectType);
            feeAmountObject.AddMember("amount", feeArray, allocator);
            auto gasLimit = _gasLimit->toString();
            vString.SetString(gasLimit.c_str(), static_cast<rapidjson::SizeType>(gasLimit.length()), allocator);
            feeAmountObject.AddMember("gas", vString, allocator);
            Value vDouble(rapidjson::kNumberType);
            if (_gasAdjustment > 0) {
                vDouble.SetDouble(_gasAdjustment);
                feeAmountObject.AddMember("gas_adjustment", vDouble, allocator);
            }
            document.AddMember("fee", feeAmountObject, allocator);

            vString.SetString(_memo.c_str(), static_cast<rapidjson::SizeType>(_memo.length()), allocator);
            document.AddMember("memo", vString, allocator);

            //cosmos-sdk/MsgSend
            Value msgValueObject(kObjectType);
            auto amountObj = getAmountObject(_value->getUnit().name, _value->toString());
            msgValueObject.AddMember("value", amountObj, allocator);
            auto from =  _sender->toBech32();
            vString.SetString(from.c_str(), static_cast<rapidjson::SizeType>(from.length()), allocator);
            msgValueObject.AddMember("from", vString, allocator);
            auto to = _receiver->toBech32();
            vString.SetString(to.c_str(), static_cast<rapidjson::SizeType>(to.length()), allocator);
            msgValueObject.AddMember("to", vString, allocator);

            Value msgObject(kObjectType);
            //TODO: to change when supportig other types
            std::string msgType = "cosmos-sdk/MsgSend";
            vString.SetString(msgType.c_str(), static_cast<rapidjson::SizeType>(msgType.length()), allocator);
            msgObject.AddMember("type", vString, allocator);
            msgObject.AddMember("value", msgValueObject, allocator);

            Value msgArray(kArrayType);
            msgArray.PushBack(msgObject, allocator);

            document.AddMember("msgs", msgArray, allocator);

            vString.SetString(_sequence.c_str(), static_cast<rapidjson::SizeType>(_sequence.length()), allocator);
            document.AddMember("sequence", vString, allocator);

            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            document.Accept(writer);
            return buffer.GetString();
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setValue(const std::shared_ptr<BigInt> &value) {
            if (!value) {
                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                     "CosmosLikeTransactionApi::setValue: Invalid Value");
            }
            _value = std::make_shared<Amount>(_currency, 0, *value);
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setSender(const std::shared_ptr<api::CosmosLikeAddress> &sender) {
            _sender = sender;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setReceiver(const std::shared_ptr<api::CosmosLikeAddress> &receiver) {
            _receiver = receiver;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setSigningPubKey(const std::vector<uint8_t> &pubKey) {
            _signingPubKey = pubKey;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setHash(const std::string &hash) {
            _hash = hash;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setGasLimit(const std::shared_ptr<BigInt> &gasLimit) {
            if (!gasLimit) {
                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                     "CosmosLikeTransactionApi::setGasLimit: Invalid gas limit");
            }
            _gasLimit = std::make_shared<Amount>(_currency, 0, *gasLimit);
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setGasPrice(const std::shared_ptr<BigInt> &gasPrice) {
            if (!gasPrice) {
                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                     "CosmosLikeTransactionApi::setGasPrice: Invalid gas price");
            }
            _gasPrice = std::make_shared<Amount>(_currency, 0, *gasPrice);
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setGasAdjustment(double gasAdjustment) {
            _gasAdjustment = gasAdjustment;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setSequence(const std::string &sequence) {
            _sequence = sequence;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setMemo(const std::string &memo) {
            _memo = memo;
            return *this;
        }

        CosmosLikeTransactionApi &CosmosLikeTransactionApi::setAccountNumber(const std::string &accountNumber) {
            _accountNumber = accountNumber;
            return *this;
        }

    }
}
