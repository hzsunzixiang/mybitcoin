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
    uint32_t sht;

    COutPoint(): n((uint32_t) -1) { }
    COutPoint(uint32_t x): n(x) { }
    COutPoint(uint32_t x, uint32_t y): n(x), sht(y) { }

    ADD_SERIALIZE_METHODS;
    //template<typename Stream> void Serialize(Stream& s) const { NCONST_PTR(this)->SerializationOp(s, CSerActionSerialize()); } 
	//template<typename Stream> void Unserialize(Stream& s) { SerializationOp(s, CSerActionUnserialize()); };

    //template <typename Stream, typename Operation>
    //inline void SerializationOp(Stream& s, Operation ser_action) {
    //    READWRITE(n,sht);
    //}
    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(n);
        READWRITE(sht);
        //(::SerReadWriteMany(s, ser_action, n));
        //(::SerReadWriteMany(s, ser_action, sht));
    }

    std::string ToString() const{}
};

