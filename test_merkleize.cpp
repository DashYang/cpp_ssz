/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 
#include <ethash/ethash.hpp>
#include <ethash/keccak.hpp>

#include "include/Common.h"
#include "include/cpp_ssz_bool.h"
#include "include/cpp_ssz_uint.h"
#include "include/cpp_ssz_bytes.h"
#include "include/cpp_ssz_bytesN.h"
#include "include/cpp_ssz_list.h"
#include "include/cpp_ssz_tuple.h"
#include "include/cpp_ssz_container.h"
#include "include/cpp_ssz_util.h"

using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
    uint8_t data1[4] = {0x1,0x2,0x3,0x4};
    ethash::hash256 h1 = ethash::keccak256(data1, 4);
    bytes a1(h1.bytes,32);
    print_hex(a1);

    uint8_t data2[4] = {0x1,0x2,0x3,0x4};
    ethash::hash256 h2 = ethash::keccak256(data2, 4);
    bytes a2(h2.bytes,32);
    print_hex(a2);

    bytes sum;
    sum.insert(sum.end(), a1.begin(), a1.end());
    sum.insert(sum.end(), a2.begin(), a2.end());
    print_hex(sum);
    ethash::hash256 h3 = ethash::keccak256(sum.data(), 64);
    bytes a3(h3.bytes,32);
    print_hex(a3);

    return 0;
}
