#ifndef __CPP_SSZ_H__
#define __CPP_SSZ_H__

#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

typedef unsigned char byte;
#define HEXARY 		16
#define LENGTH_BYTES 	4
#define SSZ_CHUNK_SIZE 	128

#define DEBUG

enum SupportedTypes {
	type_BOOL,
	type_UINT8,
	type_UINT16,
	type_UINT32,
	type_UINT64,
	type_BYTES,
	type_STRUCT,
	type_ARRAY,
};

class CppSsz
{
public:
	void print_encoded_hexary(byte* source, int size)
	{
		for(int i=0; i<size; i++)
		{
			printf("%02x ", source[i]);
		}
		printf("\n");
	}

	void Write_prefix(byte* dst, int prefix)
	{
		assert(dst);
		dst[0] = (byte)((prefix & 0x00ff0000) >> 16);
		dst[1] = (prefix >> 8) & 0xff;
		dst[2] = (prefix >> 0) & 0xff;
	}

	virtual byte* Encode(void* in) = 0;
	virtual int Decode(void* out, const byte* in) = 0;
};
#endif
