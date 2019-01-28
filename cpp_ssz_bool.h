#ifndef __CPP_SSZ_BOOL_H__
#define __CPP_SSZ_BOOL_H__
#include "cpp_ssz.h"

class CppSszBool: public CppSsz 
{
public:
	byte* Encode(void* in);
	int Decode(void* out, const byte* in);
};
#endif
