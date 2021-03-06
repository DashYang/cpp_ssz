#ifndef __CPP_SSZ_H__
#define __CPP_SSZ_H__

#include <stdio.h>
#include <string.h>
#include <vector>
#include "cpp_ssz_constant.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_bytes.h"
using namespace std;

template <class T>
class cpp_ssz_codec
{
public:
	cpp_ssz_codec(){};

	T* m_value;
	unsigned int m_count;
	cpp_ssz_types* m_item_list;

	T* from_bytes(byte* bytes, byteorder bo);
	byte* to_bytes(unsigned int size, byteorder bo);
};

#include "cpp_ssz.hpp"

#endif
