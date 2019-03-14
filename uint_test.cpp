/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_uint.h"
using namespace std;

//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x ", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

using u256 =  boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;

int main()
{
    uint256 c(8);
    cout << c.data() << endl;
    CHECK_SUCESS(c.data(), u256(8));
}

