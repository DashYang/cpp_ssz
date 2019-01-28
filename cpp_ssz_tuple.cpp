#include "cpp_ssz_tuple.h"
#include <iostream>
#include <string.h>
using namespace std;

#define DEBUG

byte* CppSszTuple::Encode(void* in)
{
	assert(in);

	Tuple* pTuple = (Tuple*)in;
	int k_len = strlen(pTuple->GetKey());
	int k_prefix = 8388608 + k_len;
	int v_len = strlen(pTuple->GetValue());
	int v_prefix = 8388608 + v_len;
	int prefix = 8388608 + k_len + v_len + 6;

	byte* ret = new byte[3*3+k_len+v_len];
	assert(ret);

	int pos = 0;
	Write_prefix(ret+pos, prefix); 
	pos += 3;

#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif

	Write_prefix(ret+pos, k_prefix); 
	pos += 3;
#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif

	strncpy(reinterpret_cast<char*>(ret+pos), reinterpret_cast<char*>(pTuple->GetKey()), k_len);
	pos += k_len;
#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif

	Write_prefix(ret+pos, v_prefix); 
	pos += 3;
#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif
	strncpy(reinterpret_cast<char*>(ret+pos), reinterpret_cast<char*>(pTuple->GetValue()), v_len);
	pos += v_len;
#ifdef DEBUG
	print_encoded_hexary(ret, pos);
#endif
	return ret;
}


int CppSszTuple::Decode(void* out, const byte* in)
{
	assert(out);
	assert(in);
	return 0;
}

