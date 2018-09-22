
#include <stdio.h>
#include <string>
#include <iostream>
#include <config/bitcoin-config.h>
#include <serialize.h>
#include <streams.h>
#include <tx.h>
#include <config/bitcoin-config.h>
#include <utilstrencodings.h>
#include <hash.h>
using namespace std;

std::string EncodeHexTx(const COutPoint& tx, const int serializeFlags = 0);
std::string DecodeHexTx(const COutPoint& tx, const int serializeFlags = 0);
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

std::string DecodeHexTx(const COutPoint& tx, const int serializeFlags)
{
    //CDataStream ssTx(SER_NETWORK, PROTOCOL_VERSION | serializeFlags);
    CDataStream ssTx(SER_NETWORK, serializeFlags);
    ssTx << tx;
	// 这是序列化 简单类型
	// 测试直接调用 serialize.h 中的序列化
    ::Serialize(ssTx, 0x101111213);
    ::Serialize(ssTx, (short)0x1011);

	// 开始反序列化
	COutPoint tx1;
	ssTx >> tx1;
	cout << tx1.ToString() << endl;
	return tx1.ToString();
	
}

int testDecode(int argc, char **argv)
{
	printf("version:%s\n", PACKAGE_VERSION);
    COutPoint x(0x12345678, 0xabcdefac);

	//string && str = EncodeHexTx(x, 0);
	string && str = DecodeHexTx(x);
    cout << str << endl;
    return 0;
}
int main(int argc, char **argv)
{
	CHashWriter ss(SER_GETHASH, 0);
	ss << 0x1000000;
    cout << HexStr(ss.GetHash()) << endl;

	return 0;
}
//结果符合
// printf "00000001" |xxd -r -p |sha256sum -b |xxd -r -p |sha256sum -b
//ericksun@192.168.56.101:~/mybitcoin/gethash/src$ printf "00000001" |xxd -r -p |sha256sum -b |xxd -r -p |sha256sum -b
	//fcb88451969c719dad97e8ccf435a72b60b4f9310a3073e6df11ba7dd14e6573 *-


