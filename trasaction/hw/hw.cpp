/* @(#)hw.cpp
 *
 * 
 *  Copyright (C) 2013, GC3, University of Zurich. All rights
 *  reserved.
 *
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <stdio.h>
#include <string>
#include <iostream>

#include <cli.h>

#include <config/bitcoin-config.h>
#include <hwmath.h>
#include <serialize.h>
#include <streams.h>
#include <tx.h>
#include <utilstrencodings.h>
using namespace std;

std::string EncodeHexTx(const COutPoint& tx, const int serializeFlags = 0);
std::string EncodeHexTx(const COutPoint& tx, const int serializeFlags)
{
    //CDataStream ssTx(SER_NETWORK, PROTOCOL_VERSION | serializeFlags);
    CDataStream ssTx(SER_NETWORK, serializeFlags);
    ssTx << tx;
	// 这是序列化 简单类型
	// 测试直接调用 serialize.h 中的序列化
    ::Serialize(ssTx, 0x101111213);
    ::Serialize(ssTx, (short)0x1011);
    return HexStr(ssTx.begin(), ssTx.end());
}

int main(int argc, char **argv){
	printf("version:%s\n", PACKAGE_VERSION);
    COutPoint x(0x12345678, 0xabcdefac);

	//string && str = EncodeHexTx(x, 0);
	string && str = EncodeHexTx(x);
    cout << str << endl;
    return 0;
}
