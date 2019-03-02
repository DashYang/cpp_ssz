#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include <stdio.h>
#include <string.h>
#include <vector>
#include "cpp_ssz_constant.h"
using namespace std;

template<unsigned int N>
class uint 
{
protected:
	unsigned int m_size;
	byte* m_value;
public:
	uint() 
	{ 
		m_size = N/8;
		m_value = new byte[m_size];
		memset(m_value, 0 , m_size); 
	}
	uint(const unsigned long long int value) 
	{ 
		m_size = N/8;
		m_value = new byte[m_size];
		memcpy(m_value, &value , m_size); 
	}
	~uint()
	{
		delete m_value;
	}

	unsigned int size() const { return m_size; }
	byte* get_bytes() const { return m_value; }

//Assigned operator
//pure type
	uint& operator=(const unsigned long long int value)
	{
		memcpy(m_value, &value , m_size); 
		return *this;
	}

//self
	uint& operator=(const uint& value)
	{
		memcpy(m_value, value.get_byte() , m_size); 
		return *this;
	}

//codec section
	uint* from_bytes(byte* bytes, byteorder bo);
	byte* to_bytes(unsigned int size, byteorder bo);
	
//pretty printer section
	inline void print_hex() {
		for(int i=0; i<m_size; i++)
			printf("%02x ", m_value[i]);
		printf("\n");
	}
};

class uint8 : public uint<8> 
{
public:
	uint8() {}
	uint8(const unsigned long long int val):uint(val){}
};

class uint256 : public uint<256> 
{
public:
	uint256() {}
	uint256(const unsigned long long int val):uint(val){}
};


#endif
