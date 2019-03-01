#ifndef __CPP_SSZ_BOOL_H__
#define __CPP_SSZ_BOOL_H__

#include "cpp_ssz.h"
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

class BOOL
{
protected:
	bool m_value;
public:
	BOOL() 
	{ 
		m_value = false; 
	}
	BOOL(bool value) 
	{ 
		m_value = value; 
	}
	bool get_bool() const { return m_value; }

//Assigned operator
//pure type
	BOOL& operator=(bool b)
	{
		m_value = b; 
		return *this;
	}

//self
	BOOL& operator=(BOOL& b)
	{
		m_value = b.get_bool(); 
		return *this;
	}

//codec section
	bool from_bytes(byte* bytes, byteorder bo);
	byte* to_bytes(unsigned int size, byteorder bo);
	
};

#endif
