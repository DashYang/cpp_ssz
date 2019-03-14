/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "Common.h"
#include "cpp_ssz_bytes.h"
using namespace std;


//pretty printer section
void print_hex(const bytes& a) {
		for(int i=0; i<a.size(); i++)
			printf("%02x ", a.data()[i]);
		printf("\n");
}

#define CHECK_SUCESS(a,b){ a==b ? cout << "\033[1;32mSUCCESS\033[0m\n": cout << "\033[1;31mFAIL\033[0m\n;";}

int main()
{
// initial values  
    string s_over = "abcdefghijk";
    string s_fit = "abcdefgh";
    string s_under = "abcde";

    bytes b_over(s_over.begin(), s_over.end());
    bytes b_fit(s_fit.begin(), s_fit.end());
    bytes b_under(s_under.begin(), s_under.end());

// byte8
    {
        bytes8 testval(s_over);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
    {
        bytes8 testval(s_fit);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
    {
        bytes8 testval(s_under);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
    {
        bytes8 testval(b_over);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
    {
        bytes8 testval(b_fit);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
    {
        bytes8 testval(b_under);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }

    {
        bytesN<16> testval(s_under);
        bytes enc = testval.to_bytes(16,little);
        print_hex(enc);

        bytesN<16> dec;
        dec.from_bytes(enc, little);

        CHECK_SUCESS(testval, dec);
    }
}

