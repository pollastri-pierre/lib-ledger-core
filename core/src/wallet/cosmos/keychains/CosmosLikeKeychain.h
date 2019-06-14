/*
 *
 * CosmosLikeKeychain
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


#ifndef LEDGER_CORE_COSMOSLIKEKEYCHAIN_H
#define LEDGER_CORE_COSMOSLIKEKEYCHAIN_H

#include <string>
#include <vector>
#include <utils/DerivationScheme.hpp>
#include <utils/Option.hpp>
#include <preferences/Preferences.hpp>
#include <api/Configuration.hpp>
#include <api/DynamicObject.hpp>
#include <api/Currency.hpp>
#include <api/AccountCreationInfo.hpp>
#include <api/ExtendedKeyAccountCreationInfo.hpp>
#include <api/CosmosLikeExtendedPublicKey.hpp>
#include <cosmos/CosmosLikeAddress.h>
#include <common/CommonAccountBasedKeychain.h>

namespace ledger {
    namespace core {
        class CosmosLikeKeychain : public CommonAccountBasedKeychain<CosmosLikeAddress, api::CosmosLikeExtendedPublicKey, api::CosmosLikeNetworkParameters> {
        public:
            CosmosLikeKeychain(const std::shared_ptr<api::DynamicObject> &configuration,
                               const api::Currency &params,
                               const std::shared_ptr<Preferences> &preferences);


            CosmosLikeKeychain(const std::shared_ptr<api::DynamicObject> &configuration,
                               const api::Currency &params,
                               const std::shared_ptr<api::CosmosLikeExtendedPublicKey> &xpub,
                               const std::shared_ptr<Preferences> &preferences);

            CosmosLikeKeychain(const std::shared_ptr<api::DynamicObject> &configuration,
                               const api::Currency &params,
                               const std::string &accountAddress,
                               const std::shared_ptr<Preferences> &preferences);

            const api::CosmosLikeNetworkParameters &getNetworkParameters() const override;
        };
    }
}
#endif //LEDGER_CORE_COSMOSLIKEKEYCHAIN_H
