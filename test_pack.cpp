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
        List<Bool> testval;
        Bool a0(true);
        Bool a1(false);
        Bool a2(true);
        Bool a3(false);
        testval.push_back(a0);
        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);
        bytes packed = pack(testval);
        print_hex(packed);
        
    }
    {
        List<uint8> testval;
        uint8 a0(1);
        uint8 a1(2);
        uint8 a2(3);
        uint8 a3(4);
        testval.push_back(a0);
        testval.push_back(a1);
        testval.push_back(a2);
        testval.push_back(a3);
        bytes packed = pack(testval);
        print_hex(packed);
    }
    {
        List<uint16> testval;
        uint16 a0(1);
        uint16 a1(2);
        testval.push_back(a0);
        testval.push_back(a1);
        bytes packed = pack(testval);
        print_hex(packed);
    }
    return 0;
}
