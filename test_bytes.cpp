/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
using namespace std;
using namespace ssz;


//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x ", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(testname, a,b){ cout<< testname << " "; a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n";}

int main()
{
/*
        (b"", b'\x00\x00\x00\x00'),
        (b"I", b'\x01\x00\x00\x00I'),
        (b"foo", b'\x03\x00\x00\x00foo'),
        (b"hello", b'\x05\x00\x00\x00hello'),
*/

// bytes
    {
        bytes testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        bytes dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("bytes",testval, dec);
    }
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

