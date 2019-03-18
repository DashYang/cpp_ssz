/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
#include "cpp_ssz_bytesN.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_container.h"
using namespace std;
using namespace ssz;

#include "test.h"

int main()
{
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);
    bytes b("abcdefg");

    Container<bytes32,uint256> a; 
    a.push_back(std::make_pair(bytes32(b),testval));
    bytes enc = a.to_bytes(0, little);
    print_hex(enc);
}

