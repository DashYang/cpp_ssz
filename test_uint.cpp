/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#include "include/Common.h"
#include "include/cpp_ssz_uint.h"
using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
/*
@pytest.mark.parametrize(
    'value,sedes,expected',
    (
        (0, uint8, b'\x00'),
        (5, uint8, b'\x05'),
        (127, uint8, b'\x7f'),
        (255, uint8, b'\xff'),

        (0, uint16, b'\x00\x00'),
        (5, uint16, b'\x05\x00'),
        (127, uint16, b'\x7f\x00'),
        (256, uint16, b'\x00\x01'),
        (1024, uint16, b'\x00\x04'),
        (65535, uint16, b'\xff\xff'),

        (0, uint32, b'\x00\x00\x00\x00'),
        (5, uint32, b'\x05\x00\x00\x00'),
        (65536, uint32, b'\x00\x00\x01\x00'),
        (4294967295, uint32, b'\xff\xff\xff\xff'),

        (0, uint64, b'\x00\x00\x00\x00\x00\x00\x00\x00'),
        (18446744073709551615, uint64, b'\xff\xff\xff\xff\xff\xff\xff\xff'),
    ),
)
*/
    {
        u256 a("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
        uint256 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint256 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint256", testval, dec);
    }
    {
        u128 a("0x16b3dfaec148fb1bb2b066f10ec285e7");
        uint128 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint128 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint128", testval, dec);
    }
    {
        u64 a(18446744073709551615);
        uint64 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint64 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint64", testval, dec);
    }
    {
        u32 a(4294967295);
        uint32 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint32 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint32", testval, dec);
    }
    {
        u16 a(65535);
        uint16 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint16 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint16", testval, dec);
    }
    {
        u8 a(255);
        uint8 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);
        print_hex(enc);

        uint8 dec;
        dec.from_bytes(enc, little);
        CHECK_SUCESS("uint8", testval, dec);
    }
}

