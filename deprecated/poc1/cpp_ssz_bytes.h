#ifndef __CPP_SSZ_BYTES_H__
#define __CPP_SSZ_BYTES_H__

#include <stdio.h>
#include <string.h>
#include <vector>
#include "cpp_ssz_constant.h"
using namespace std;

template<unsigned int N>
class bytes
{
protected:
	unsigned int m_size;
	byte* m_value;
public:
	bytes() 
	{ 
		m_size = N;
		m_value = new byte[m_size];
		memset(m_value, 0 , m_size); 
	}
	bytes(const byte* value) 
	{ 
		m_size = N;
		m_value = new byte[m_size];
		memcpy(m_value, value , m_size); 
	}
	~bytes()
	{
		delete m_value;
	}

	unsigned int size() const { return m_size; }
	byte* get_bytes() const { return m_value; }

//Assigned operator
//pure type
	bytes& operator=(const byte* b)
	{
		memcpy(m_value, b, m_size); 
		return *this;
	}

//self
	bytes& operator=(const bytes& b)
	{
		memcpy(m_value, b.get_bytes(), m_size); 
		return *this;
	}

//codec section
	bytes* from_bytes(byte* bytes, byteorder bo);
	byte* to_bytes(unsigned int size, byteorder bo);
	
//pretty printer section
	inline void print_hex() {
		for(int i=0; i<m_size; i++)
			printf("%02x ", m_value[i]);
		printf("\n");
	}
};

class bytes4 : public bytes<4> 
{
public:
	bytes4() {}
	bytes4(byte* val):bytes(val){}
	bytes4(char* val):bytes(reinterpret_cast<byte*>(val)){}
};

class bytes8 : public bytes<8> 
{
public:
	bytes8() {}
	bytes8(byte* val):bytes(val){}
	bytes8(char* val):bytes(reinterpret_cast<byte*>(val)){}
};


#endif
