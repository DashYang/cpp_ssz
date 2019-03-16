/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_list.h"
#include "cpp_ssz_container.h"
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
/*
    uint256 testval1("0x1111111111111111111111111111111111111111111111111111111111111111");
    string s_over = "abcdefghijk";
    bytes b_over(s_over.begin(), s_over.end());

    Container<bytes8,uint256> a; 
    a.data().push_back(std::make_pair(bytes8(b_over),testval1));
    bytes enc = a.to_bytes(0, little);
    print_hex(enc);
*/
}

