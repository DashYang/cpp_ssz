/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include "Common.h"
#include "cpp_ssz_bytes.h"
using namespace std;

namespace ssz {
template<class T, unsigned int N>
class uint
{
protected:
	unsigned int m_size;
    T m_data;
public:
	uint() 
	{ 
        assert(!(N % 8));
		m_size = N / 8;
        m_data = 0;
	}

	uint(const T& a) 
	{ 
        assert(!(N % 8));
		m_size = N / 8;
        m_data = a;
	}

	~uint()
	{

	}

	unsigned int size() const { return m_size; }
	const T& data() const { return m_data; }

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
	bool operator==(const T& b)
	{
	     return this->m_data == b;
	}
	bool operator==(const uint& b)
	{
	     return this->m_data == b.data();
	}
};

template<class T, unsigned int N>
void uint<T, N>::from_bytes(bytes& data, byteorder bo)
{
    //assert(data.size() == (N/8));
    m_data = 0;
    if(bo == little) {
        for(int i=0; i< m_size; i++) 
            m_data += static_cast<T>(data[i]) << (i*8);
    }
    else {
        for(int i=m_size-1; i >= 0 ; i--)
            m_data += static_cast<T>(data[i]) << (i*8);
    }
}

template<class T, unsigned int N>
bytes uint<T, N>::to_bytes(unsigned int size, byteorder bo)
{
    bytes temp;
    if(bo == little) {
        for(int i=0; i< m_size; i++)
            temp.push_back(reinterpret_cast<byte*>(&m_data)[i]);
    }
    else { 
        for(int i=m_size-1; i >= 0 ; i--)
            temp.push_back(reinterpret_cast<byte*>(&m_data)[i]);
    }
	return bytes(temp); 
}
//Shorten types
class uint8 : public uint<u8, 8> 
{
public:
    uint8() {}
    uint8(const u8& data):uint(data) {}
};

class uint16 : public uint<u16, 16> 
{
public:
    uint16() {}
    uint16(const u16& data):uint(data) {}
};


class uint32 : public uint<u32, 32> 
{
public:
    uint32() {}
    uint32(const u32& data):uint(data) {}
};

class uint64 : public uint<u64, 64> 
{
public:
    uint64() {}
    uint64(const u64& data):uint(data) {}
};

class uint128 : public uint<u128, 128> 
{
public:
    uint128() {}
    uint128(const u128& data):uint(data) {}
};

class uint256 : public uint<u256, 256> 
{
public:
    uint256() {}
    uint256(const u256& data):uint(data) {}
};

}//namespace
#endif




