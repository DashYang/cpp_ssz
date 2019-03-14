/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_COMMON_H__
#define __CPP_SSZ_COMMON_H__

#include <string>
#include <vector>
#include <assert.h>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

namespace ssz {

const unsigned int LENGTH_BYTES = 4;
const unsigned int  SSZ_CHUNK_SIZE = 128;

enum byteorder {
	little,
};

using byte = uint8_t;
using bytes = std::vector<byte>;
using u256 =  boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;

}

#endif
