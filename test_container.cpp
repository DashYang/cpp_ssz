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

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x", a[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

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

