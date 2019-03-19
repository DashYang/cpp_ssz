/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "include/Common.h"
#include "include/cpp_ssz_bytes.h"
#include "include/cpp_ssz_bytesN.h"
#include "include/cpp_ssz_uint.h"
#include "include/cpp_ssz_list.h"
using namespace std;
using namespace ssz;

#include "include/test.h"

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
        List<uint32> testval;

        uint32 a0(1);
        uint32 a1(2);
        uint32 a2(3);
        uint32 a3(4);
        uint32 a4(5);

        testval.push_back(a0);
        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);
        testval.push_back(a4);

        bytes enc = testval.to_bytes(a0.size(), little);
        print_hex(enc);

        List<uint32> dec;
        dec.from_bytes(enc, little);
        bytes re_enc = dec.to_bytes(a0.size(), little);
        print_hex(re_enc);
        CHECK_SUCESS("List<uint32>",enc, re_enc);
    }

    {
        List<bytes48> testval;
        bytes48 a1("abcd");
        bytes48 a2("abcd");

        testval.push_back(a1);
        testval.push_back(a2);
        bytes enc = testval.to_bytes(a1.size(), little);
        print_hex(enc);

        List<bytes48> dec;
        dec.from_bytes(enc, little);
        bytes re_enc = dec.to_bytes(a1.size(), little);
        print_hex(re_enc);
        CHECK_SUCESS("List<bytes48>",enc, re_enc);
    }
}

