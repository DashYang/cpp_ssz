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

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

int main()
{
// initial values  
    uint256 testval1("0x1111111111111111111111111111111111111111111111111111111111111111");
    uint256 testval2("0x2222222222222222222222222222222222222222222222222222222222222222");
    uint256 testval3("0x3333333333333333333333333333333333333333333333333333333333333333");
    Tuple<uint256, 3> a;
    a[0] = testval1;
    a[1] = testval2;
    a[2] = testval3;

    bytes enc = a.to_bytes(0, little);
    print_hex(enc);
    
}

