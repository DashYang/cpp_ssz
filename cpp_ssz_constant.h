#ifndef __CPP_SSZ_CONSTANT_H__
#define __CPP_SSZ_CONSTANT_H__

typedef unsigned char byte;
const unsigned int LENGTH_BYTES = 4;
const unsigned int  SSZ_CHUNK_SIZE = 128;

enum byteorder {
	little,
};

enum cpp_ssz_types {
	type_BOOL,
	type_UINT8,
	type_UINT24,
	type_BYTES4,
	type_BYTES8,
	type_LIST,
	type_CONTAINER,
};

#endif
