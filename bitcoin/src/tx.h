// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <serialize.h>

static const int SERIALIZE_TRANSACTION_NO_WITNESS = 0x40000000;

class COutPoint
{
public:
    uint32_t n;

    COutPoint(): n((uint32_t) -1) { }
    COutPoint(uint32_t x): n(x) { }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(n);
    }

    std::string ToString() const{}
};

