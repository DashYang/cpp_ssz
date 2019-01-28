#include "cpp_ssz_bool.h"
#include <iostream>
#include <string.h>
using namespace std;

byte* CppSszBool::Encode(void* in)
{
	assert(in);

	bool* pBool = (bool*)in;
	int prefix = 8388608 + 1;

	byte* ret = new byte[4];
	assert(ret);

	int pos = 0;
	Write_prefix(ret, prefix); 
	pos += 3;

#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif
	if(*pBool) ret[3] = 0x01;
	else ret[3] = 0x00;
	pos += 1;
#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif
	return ret;
}


int CppSszBool::Decode(void* out, const byte* in)
{
	assert(out);
	assert(in);
	return 0;
}

