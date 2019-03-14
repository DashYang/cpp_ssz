/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_COMMON_H__
#define __CPP_SSZ_COMMON_H__

#include <string>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

#include <assert.h>

const unsigned int LENGTH_BYTES = 4;
const unsigned int  SSZ_CHUNK_SIZE = 128;

enum byteorder {
	little,
};

using byte = uint8_t;
using bytes = std::vector<byte>;

#endif
