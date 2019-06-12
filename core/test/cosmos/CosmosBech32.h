/*
 *
 * CosmosBech32
 *
 * Created by El Khalil Bellakrid on 12/06/2019.
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


#ifndef LEDGER_CORE_COSMOSBECH32_H
#define LEDGER_CORE_COSMOSBECH32_H

#include <bitcoin/bech32/Bech32Factory.h>
#include <bitcoin/bech32/BTCBech32.h>
#include <bitcoin/bech32/Bech32Parameters.h>

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

#endif //LEDGER_CORE_COSMOSBECH32_H
