#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include "cpp_ssz.h"
#include <stdio.h>
#include <string.h>
#include <vector>
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

	uint operator=(const unsigned long long int value);

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
	uint8(unsigned int val):uint(val){}
};

class uint256 : public uint<256> 
{
public:
	uint256() {}
	uint256(unsigned int val):uint(val){}
};


#endif
