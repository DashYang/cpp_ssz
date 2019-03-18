/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_tuple.h"
using namespace std;
using namespace ssz;

#include "test.h"

int main()
{
// initial values  
    Tuple<uint256, 3> a;
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);
    a[0] = testval;
    a[1] = testval;
    a[2] = testval;

    bytes enc = a.to_bytes(0, little);
    print_hex(enc);
}

