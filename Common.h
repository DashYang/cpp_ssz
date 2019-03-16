/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_COMMON_H__
#define __CPP_SSZ_COMMON_H__

#include <string>
#include <vector>
#include <map>
#include <assert.h>
//#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

namespace ssz {

const unsigned int LENGTH_BYTES = 4;
const unsigned int SSZ_CHUNK_SIZE = 128;
//const unsigned int SSZ_PREFIX = 8388608;
const unsigned int SSZ_PREFIX = 0;

enum byteorder {
	little,
};

enum cpp_ssz_types_enum {
	type_BOOL,
	type_UINT,
	type_BYTES,
	type_LIST,
	type_CONTAINER,
};

using byte = uint8_t;
using bytes = std::vector<byte>;
using u256 =  boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>>;

class cpp_ssz_types 
{
public:
//    cpp_ssz_types_enum my_type;
//    cpp_ssz_types_enum container_list[2];
    virtual void from_bytes(const bytes& data, byteorder bo) = 0;
	virtual bytes to_bytes(unsigned int size, byteorder bo) = 0;
};

}

#endif
