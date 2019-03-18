/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytesN.h"
using namespace std;
using namespace ssz;

#include "test.h"

int main()
{
// bytes32
    {
        bytes32 testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        bytes32 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bytes32",testval, dec);
    }
// bytes48
    {
        bytes48 testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        bytes48 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bytes48",testval, dec);
    }
// bytes96
    {
        bytes96 testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        bytes96 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bytes96",testval, dec);
    }
}

