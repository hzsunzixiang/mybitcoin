#include <stdio.h>
#include <string>
#include <iostream>

#include <config/bitcoin-config.h>
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
    return HexStr(ssTx.begin(), ssTx.end());
}

int main(int argc, char **argv){
	printf("version:%s\n", PACKAGE_VERSION);
    COutPoint x(0x12345678);

	//string && str = EncodeHexTx(x, 0);
	string && str = EncodeHexTx(x);
    cout << str << endl;
    return 0;
}
