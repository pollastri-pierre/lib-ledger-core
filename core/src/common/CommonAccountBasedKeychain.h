/*
 *
 * CommonAccountBasedKeychain
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


#ifndef LEDGER_CORE_COMMONACCOUNTBASEDKEYCHAIN_H
#define LEDGER_CORE_COMMONACCOUNTBASEDKEYCHAIN_H

#include <api/Currency.hpp>
#include <api/KeychainEngines.hpp>
#include <cereal/cereal.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/set.hpp>

namespace ledger {
    namespace core {
        template<typename Address, typename ExtendedPublicKey, typename NetworkParameters>
        class CommonAccountBasedKeychain {
        public:

            virtual const NetworkParameters &getNetworkParameters() const = 0;

            std::shared_ptr<Preferences> getPreferences() const {
                return _preferences;
            };

            std::shared_ptr<api::DynamicObject> getConfiguration() const {
                return _configuration;
            };

            const api::Currency &getCurrency() const {
                return _currency;
            };

            const DerivationScheme &getDerivationScheme() const {
                return _scheme;
            };

            DerivationScheme &getDerivationScheme() {
                return _scheme;
            };

            const DerivationScheme &getFullDerivationScheme() const {
                return _fullScheme;
            };


            virtual std::shared_ptr<Address> getAddress() const {
                if (_address.empty()) {
                    throw Exception(api::ErrorCode::INVALID_ARGUMENT,
                                    fmt::format("Address not derived yet from keychain"));
                }
                return std::dynamic_pointer_cast<Address>(
                        Address::parse(_address, getCurrency(), Option<std::string>(_localPath)));
            };

            Option <std::string> getAddressDerivationPath(const std::string &address) const {
                auto path = getPreferences()->getString(fmt::format("address:{}", address), "");
                if (path.empty()) {
                    return Option<std::string>();
                } else {
                    auto derivation = DerivationPath(getExtendedPublicKey()->getRootPath()) + DerivationPath(path);
                    return Option<std::string>(derivation.toString());
                }
            };

            std::vector<std::shared_ptr<Address>>
            getAllObservableAddresses(uint32_t from, uint32_t to) {
                std::vector<std::shared_ptr<Address>> result;
                result.push_back(derive());
                return result;
            };


            std::shared_ptr<ExtendedPublicKey> getExtendedPublicKey() const {
                return _xpub;
            };

            virtual std::string getRestoreKey() const {
                return _xpub->toBase58();
            };


            bool contains(const std::string &address) const {
                return getAddressDerivationPath(address).nonEmpty();
            };

            int32_t getOutputSizeAsSignedTxInput() const {
                throw make_exception(api::ErrorCode::IMPLEMENTATION_IS_MISSING,
                                     "getOutputSizeAsSignedTxInput is not implemented yet");
            };

            virtual Option <std::vector<uint8_t>> getPublicKey(const std::string &address) const {
                auto path = getPreferences()->getString(fmt::format("address:{}", address), "");
                if (path.empty()) {
                    Option<std::vector<uint8_t>>();
                }
                return Option<std::vector<uint8_t>>(_xpub->derivePublicKey(path));
            };

            virtual std::shared_ptr<Address> derive() {

                if (_address.empty()) {
                    _localPath = getDerivationScheme()
                            .setCoinType(getCurrency().bip44CoinType)
                            .getPath().toString();

                    auto cacheKey = fmt::format("path:{}", _localPath);
                    _address = getPreferences()->getString(cacheKey, "");
                    if (_address.empty()) {
                        auto p = getDerivationScheme().getSchemeFrom(DerivationSchemeLevel::NODE).shift(1)
                                .setCoinType(getCurrency().bip44CoinType)
                                .getPath().toString();
                        auto xpub = _xpub;
                        auto abstractAddress = std::dynamic_pointer_cast<AbstractAddress>(xpub->derive(p));
                        if (!abstractAddress) {
                            throw Exception(api::ErrorCode::INVALID_ARGUMENT, "To use common keychain, Address should derive from AbstractAddress");
                        }
                        _address = abstractAddress->toString();
                        // Feed path -> address cache
                        // Feed address -> path cache
                        getPreferences()
                                ->edit()
                                ->putString(cacheKey, _address)
                                ->putString(fmt::format("address:{}", _address), _localPath)
                                ->commit();
                    }
                }

                auto address = Address::parse(_address, getCurrency(), Option<std::string>(_localPath));
                if (!address) {
                    throw Exception(api::ErrorCode::INVALID_ARGUMENT, "Could not derive address");
                }
                return std::dynamic_pointer_cast<Address>(address);
            };

        protected:
            api::Currency _currency;
            DerivationScheme _scheme = DerivationScheme("44'/<coin_type>'/<account>'/<node>/<address>").getSchemeFrom(DerivationSchemeLevel::ACCOUNT_INDEX).shift();
            DerivationScheme _fullScheme = DerivationScheme("44'/<coin_type>'/<account>'/<node>/<address>");
            std::shared_ptr<Preferences> _preferences;
            std::shared_ptr<api::DynamicObject> _configuration;
            std::shared_ptr<ExtendedPublicKey> _xpub;
            std::string _localPath;
            std::string _address;
        };
    }
}

#endif //LEDGER_CORE_COMMONACCOUNTBASEDKEYCHAIN_H
