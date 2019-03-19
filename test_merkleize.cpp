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
#include "include/cpp_ssz_tuple.h"
#include "include/cpp_ssz_container.h"
#include "include/cpp_ssz_util.h"

using namespace std;
using namespace ssz;

#include "include/test.h"

int main()
{
    {
        List<bytes32> testval;
        bytes32 a1("abcd");
        bytes32 a2("abcd");
        bytes32 a3("abcd");

        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);

        ethash::hash256 root3 = merkleize(testval);
        bytes result1(root3.bytes,32);
        print_hex(result1);

        bytes32 a4;
        testval.push_back(a4);

        ethash::hash256 root4 = merkleize(testval);
        bytes result2(root4.bytes,32);
        print_hex(result2);
        CHECK_SUCESS("merkleize chunks", result1, result2);
    }
    
    return 0;
}
