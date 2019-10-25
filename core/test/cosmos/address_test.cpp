/*
 *
 * address_test
 *
 * Created by El Khalil Bellakrid on 09/06/2019.
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

#include <gtest/gtest.h>
#include <ledger/core/utils/hex.h>
#include <ledger/core/utils/optional.hpp>
#include <ledger/core/api/Networks.hpp>
#include <wallet/currencies.hpp>
#include <api/Address.hpp>
#include <utils/hex.h>
#include <bitcoin/bech32/Bech32Factory.h>
#include <bitcoin/bech32/BTCBech32.h>
#include <bitcoin/bech32/Bech32Parameters.h>
#include <collections/vector.hpp>
#include <crypto/HashAlgorithm.h>
#include <crypto/HASH160.hpp>
#include <crypto/BLAKE.h>
#include <collections/DynamicObject.hpp>
#include <math/Base58.hpp>

using namespace ledger::core::api;
using namespace ledger::core;

namespace ledger {
    namespace core {
        class CosmosBech32 : public BTCBech32 {
        public:
            CosmosBech32(bool isPubKey = false) : BTCBech32("btc", 0) {
                static const Bech32Parameters::Bech32Struct COSMOS = {
                        "cosmos",
                        "cosmos",
                        "1",
                        6,
                        {0x3b6a57b2ULL, 0x26508e6dULL, 0x1ea119faULL, 0x3d4233ddULL, 0x2a1462b3ULL},
                        {0x01},
                        {0x01}
                };

                static const Bech32Parameters::Bech32Struct COSMOS_PUB = {
                        "cosmos",
                        "cosmospub",
                        "1",
                        6,
                        {0x3b6a57b2ULL, 0x26508e6dULL, 0x1ea119faULL, 0x3d4233ddULL, 0x2a1462b3ULL},
                        {0x00},
                        {0x00}
                };
                _bech32Params = isPubKey ? COSMOS_PUB : COSMOS;
            };
        };
    }
}

TEST(CosmosAddress, AddressFromPubKey) {
    {
        // Results returned by device
        std::string prefixedPubKey = "cosmospub1addwnpepqtztanmggwrgm92kafpagegck5dp8jc6frxkcpdzrspfafprrlx7gmvhdq6";
        std::string bech32Addr = "cosmos1x9fzdaykfcc3k4hvflzu4rc6683a7cgkqfhe0s";

        // From bech32 pubKey to pubKeyHash160
        auto pkBech32 = std::make_shared<CosmosBech32>(true);
        auto pkDecodedHash160 = pkBech32->decode(prefixedPubKey);

        // Byte array to encode : <PrefixBytes> <Length> <ByteArray> hence the + 5
        std::vector<uint8_t> secp256k1PubKey(pkDecodedHash160.second.begin() + 5, pkDecodedHash160.second.end());

        std::vector<uint8_t> prefixAndSize{0xEB, 0x5A, 0xE9, 0x87, 0x21};
        auto encoded = vector::concat(prefixAndSize, secp256k1PubKey);

        // Get publicKeyHash160
        HashAlgorithm hashAlgorithm("cosmos");
        auto publicKeyHash160 = HASH160::hash(secp256k1PubKey, hashAlgorithm);

        // Encode to bech32
        auto bech32 = std::make_shared<CosmosBech32>();
        auto bech32AddrResult = bech32->encode(publicKeyHash160, std::vector<uint8_t>());
        EXPECT_EQ(bech32AddrResult, bech32Addr);
    }

    {
        // From Secp256k1 33 bytes pubkey to address
        // https://github.com/tendermint/tendermint/blob/master/docs/spec/blockchain/encoding.md#public-key-cryptography
        std::string secpPubKey = "020BD40F225A57ED383B440CF073BC5539D0341F5767D2BF2D78406D00475A2EE9";
        auto pubKey = hex::toByteArray(secpPubKey);
        HashAlgorithm hashAlgorithm("cosmos");
        auto publicKeyHash160 = HASH160::hash(pubKey, hashAlgorithm);

        // To Bech32
        auto bech32 = std::make_shared<CosmosBech32>();
        auto bech32Addr = bech32->encode(publicKeyHash160, std::vector<uint8_t>());
        std::cout<<">>> "<<bech32Addr<<std::endl;
        auto decodedHash160 = bech32->decode(bech32Addr);
        EXPECT_EQ(hex::toString(decodedHash160.second), hex::toString(publicKeyHash160));
    }
}

