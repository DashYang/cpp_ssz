/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "include/Common.h"
#include "include/cpp_ssz_bytes.h"
#include "include/cpp_ssz_uint.h"
#include "include/cpp_ssz_vector.h"
using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
// initial values  
    Vector<uint256, 3> a;
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);
    a[0] = testval;
    a[1] = testval;
    a[2] = testval;

    bytes enc = a.to_bytes(0, little);
    print_hex(enc);

    Vector<uint256, 3> dec;
    dec.from_bytes(enc, little);
    bytes re_enc = dec.to_bytes(0, little);
    print_hex(re_enc);
    CHECK_SUCESS("tuple<uint256>",enc, re_enc);
}

