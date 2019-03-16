/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_list.h"
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
/*
        (
            [0, 1, 2, 3, 4],
            uint32_list,
            b'\x14\x00\x00\x00\x00\x00\x00\x00\x01\x00\x00\x00'
            b'\x02\x00\x00\x00\x03\x00\x00\x00\x04\x00\x00\x00',
        ),
*/

    {
        u32 a1(0);
        u32 a2(1);
        u32 a3(2);
        u32 a4(3);
        u32 a5(4);
        List<uint32> testval;

        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);
        testval.push_back(a4);
        testval.push_back(a5);

        bytes enc = testval.to_bytes(0, little);
        print_hex(enc);

        List<uint32> dec;
        dec.from_bytes(enc, little);
        bytes re_enc = dec.to_bytes(0, little);
        print_hex(re_enc);
        CHECK_SUCESS("List<uint32>",enc, re_enc);
    }

    {
        bytes48 a1("hello");
        bytes48 a2("hello");
        bytes48 a3("hello");
        bytes48 a4("hello");
        bytes48 a5("hello");
        List<bytes48> testval;

        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);
        testval.push_back(a4);
        testval.push_back(a5);

        bytes enc = testval.to_bytes(0, little);
        print_hex(enc);

        List<bytes48> dec;
        dec.from_bytes(enc, little);
        bytes re_enc = dec.to_bytes(0, little);
        print_hex(re_enc);
        CHECK_SUCESS("List<uint32>",enc, re_enc);
    }
    
}

