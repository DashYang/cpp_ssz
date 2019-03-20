/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 
#include "include/Common.h"
#include "include/cpp_ssz_bool.h"
#include "include/cpp_ssz_uint.h"
#include "include/cpp_ssz_bytes.h"
#include "include/cpp_ssz_bytesN.h"
#include "include/cpp_ssz_list.h"
#include "include/cpp_ssz_vector.h"
#include "include/cpp_ssz_container.h"
#include "include/cpp_ssz_util.h"

using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
    uint8_t data1[4] = {0x1,0x2,0x3,0x4};
    ethash::hash256 root = ethash::keccak256(data1, 4);
    u256 a("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 length(a);

    ethash::hash256 mix = mix_in_length(root, length);
    bytes result(mix.bytes,32);
    print_hex(result);

    return 0;
}
