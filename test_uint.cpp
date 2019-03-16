/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_uint.h"
using namespace std;
using namespace ssz;

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(testname, a,b){ cout<< testname << " "; a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n";}

int main()
{
    {
        uint256 testval("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
        bytes enc = testval.to_bytes(256/8,little);
        print_hex(enc);

        uint256 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint256_0x", testval, dec);
    }
    {
        uint256 testval("16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
        bytes enc = testval.to_bytes(256/8,little);
        print_hex(enc);

        uint256 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint256", testval, dec);
    }
    {
        uint128 testval("0x16b3dfaec148fb1bb2b066f10ec285e7");
        bytes enc = testval.to_bytes(128/8,little);
        print_hex(enc);

        uint128 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint128_0x", testval, dec);
    }
    {
        uint128 testval("16b3dfaec148fb1bb2b066f10ec285e7");
        bytes enc = testval.to_bytes(128/8,little);
        print_hex(enc);

        uint128 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint128", testval, dec);
    }
    {
        uint64 testval("0x16b3dfaec148fb1b");
        bytes enc = testval.to_bytes(64/8,little);
        print_hex(enc);

        uint64 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint64_0x", testval, dec);
    }
    {
        uint64 testval("16b3dfaec148fb1b");
        bytes enc = testval.to_bytes(64/8,little);
        print_hex(enc);

        uint64 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint64", testval, dec);
    }
    {
        uint32 testval("0x16b3dfae");
        bytes enc = testval.to_bytes(32/8,little);
        print_hex(enc);

        uint32 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint32_0x", testval, dec);
    }
    {
        uint32 testval("16b3dfae");
        bytes enc = testval.to_bytes(32/8,little);
        print_hex(enc);

        uint32 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint32", testval, dec);
    }
    {
        uint16 testval("0x16b3");
        bytes enc = testval.to_bytes(16/8,little);
        print_hex(enc);

        uint16 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint16_0x", testval, dec);
    }
    {
        uint16 testval("16b3");
        bytes enc = testval.to_bytes(16/8,little);
        print_hex(enc);

        uint16 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint16", testval, dec);
    }
    {
        uint8 testval("0x16");
        bytes enc = testval.to_bytes(8/8,little);
        print_hex(enc);

        uint8 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint8_0x", testval, dec);
    }
    {
        uint8 testval("16");
        bytes enc = testval.to_bytes(8/8,little);
        print_hex(enc);

        uint8 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint8", testval, dec);
    }


}

