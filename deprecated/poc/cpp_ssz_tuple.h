#ifndef __CPP_SSZ_TUPLE_H__
#define __CPP_SSZ_TUPLE_H__
#include "cpp_ssz.h"

class Tuple 
{
	char* m_Key;
	char* m_Value;
public:
	Tuple():m_Key(0),m_Value(0){}
	Tuple(char* k, char* v):m_Key(k),m_Value(v){}
	char* GetKey() { return m_Key; }
	char* GetValue() { return m_Value; }

};

class CppSszTuple: public CppSsz 
{
public:
	byte* Encode(void* in);
	int Decode(void* out, const byte* in);
};
#endif
