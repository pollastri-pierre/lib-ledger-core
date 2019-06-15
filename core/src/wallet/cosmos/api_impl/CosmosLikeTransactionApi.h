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


#ifndef LEDGER_CORE_COSMOSLIKETRANSACTIONAPI_H
#define LEDGER_CORE_COSMOSLIKETRANSACTIONAPI_H

#include <wallet/common/api_impl/OperationApi.h>
#include <wallet/cosmos/api_impl/CosmosLikeBlockApi.h>
#include <api/CosmosLikeTransaction.hpp>
#include <api/Amount.hpp>
#include <api/Currency.hpp>
#include <math/BigInt.h>

namespace ledger {
    namespace core {
        class CosmosLikeTransactionApi : public api::CosmosLikeTransaction {
        public:
            explicit CosmosLikeTransactionApi(const api::Currency& currency);
            explicit CosmosLikeTransactionApi(const std::shared_ptr<OperationApi>& operation);

            std::string getHash() override;
            std::shared_ptr<api::Amount> getFees() override ;
            std::shared_ptr<api::CosmosLikeAddress> getReceiver() override ;
            std::shared_ptr<api::CosmosLikeAddress> getSender() override;
            std::shared_ptr<api::Amount> getValue() override;
            std::string serialize() override;
            std::chrono::system_clock::time_point getDate() override;
            void setSignature(const std::vector<uint8_t> & rSignature, const std::vector<uint8_t> & sSignature) override ;
            void setDERSignature(const std::vector<uint8_t> & signature) override;
            std::vector<uint8_t> getSigningPubKey() override;
            std::shared_ptr<api::Amount> getGasLimit() override;
            std::shared_ptr<api::Amount> getGasPrice() override;
            double getGasAdjustment() override;
            CosmosLikeTransactionApi & setValue(const std::shared_ptr<BigInt>& value);
            CosmosLikeTransactionApi & setSender(const std::shared_ptr<api::CosmosLikeAddress> &sender);
            CosmosLikeTransactionApi & setReceiver(const std::shared_ptr<api::CosmosLikeAddress> &receiver);
            CosmosLikeTransactionApi & setSigningPubKey(const std::vector<uint8_t> &pubKey);
            CosmosLikeTransactionApi & setHash(const std::string &hash);
            CosmosLikeTransactionApi & setGasLimit(const std::shared_ptr<BigInt>& gasLimit);
            CosmosLikeTransactionApi & setGasPrice(const std::shared_ptr<BigInt>& gasPrice);
            CosmosLikeTransactionApi & setGasAdjustment(double gasAdjustment);
        private:
            std::chrono::system_clock::time_point _time;
            std::shared_ptr<CosmosLikeBlockApi> _block;
            std::string _hash;
            api::Currency _currency;
            std::shared_ptr<api::Amount> _value;
            std::shared_ptr<api::Amount> _gasLimit;
            std::shared_ptr<api::Amount> _gasPrice;
            double _gasAdjustment;
            std::shared_ptr<api::CosmosLikeAddress> _receiver;
            std::shared_ptr<api::CosmosLikeAddress> _sender;
            std::vector<uint8_t> _rSignature;
            std::vector<uint8_t> _sSignature;
            std::vector<uint8_t> _signingPubKey;
        };
    }
}


#endif //LEDGER_CORE_COSMOSLIKETRANSACTIONAPI_H
