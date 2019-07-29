/*
 *
 * Encoder.cpp
 * ledger-core
 *
 * Created by Pierre Pollastri on 23/07/2019.
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

#include "XDREncoder.hpp"

using namespace ledger::core::stellar::xdr;

void Encoder::write(int32_t i) {
    _writer.writeBeValue<int32_t>(i);
}

void Encoder::write(uint32_t i) {
    _writer.writeBeValue<uint32_t>(i);
}

void Encoder::write(int64_t i) {
    _writer.writeBeValue<int64_t>(i);
}

void Encoder::write(uint64_t i) {
    _writer.writeBeValue<uint64_t>(i);
}

void Encoder::write(const std::string &str) {
    write((uint32_t)str.size());
    _writer.writeString(str);
}

void Encoder::write(const std::vector<uint8_t> &bytes) {
    write((uint32_t)bytes.size());
    _writer.writeByteArray(bytes);
}

void Encoder::write(const ObjectEncoder &w) {
    w(*this);
}

std::vector<uint8_t> Encoder::toByteArray() const {
    return _writer.toByteArray();
}


