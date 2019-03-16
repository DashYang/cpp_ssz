/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include "Common.h"
#include <iostream>

namespace ssz {

template<unsigned int N>
class uintN : public cpp_ssz_types
{
protected:
	unsigned int m_size;
    bytes m_data;
public:
	uintN() 
	{ 
        assert(!(N % 8));
		m_size = N / 8;
	}

	uintN(const std::string& a) 
	{ 
        assert(!(N % 8));
		m_size = N / 8;

        std::string data = a;
        if (data.size() >= 2 && data.substr(0, 2) == "0x")
            data = data.substr(2, data.size()-2);

        for (int i = 0; i < data.length(); i += 2) {
            std::string byteString = data.substr(i, 2);
            char byte = (char) strtol(byteString.c_str(), NULL, 16);
            m_data.push_back(byte);
        }
	}

	~uintN()
	{

	}

	unsigned int size() const { return m_size; }
	const bytes& data() const { return m_data; }

// encode/decode section
    void from_bytes(const bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
	bool operator==(const uintN<N>& b)
	{
	     return this->m_data == b.data();
	}

};

template<unsigned int N>
void uintN<N>::from_bytes(const bytes& data, byteorder bo)
{
    assert(data.size() == (N/8));
    if(bo == little) {
        for(int i=N/8 -1; i >= 0 ; i--)
            m_data.push_back(data[i]);
    }
    else {
        for(int i=0; i< N/8; i++)
            m_data.push_back(data[i]);
    }
}

template<unsigned int N>
bytes uintN<N>::to_bytes(unsigned int size, byteorder bo)
{
    bytes temp;
    if(bo == little) {
        for(int i=N/8 -1; i >= 0 ; i--)
            temp.push_back(m_data[i]);
    }
    else { 
        for(int i=0; i< N/8; i++)
            temp.push_back(m_data[i]);
    }
	return bytes(temp); 
}


//Shorten types
class uint8 : public uintN<8> 
{
public:
    uint8() {}
    uint8(const std::string& data):uintN(data) {}
};

class uint16 : public uintN<16> 
{
public:
    uint16() {}
    uint16(const std::string& data):uintN(data) {}
};


class uint32 : public uintN<32> 
{
public:
    uint32() {}
    uint32(const std::string& data):uintN(data) {}
};

class uint64 : public uintN<64> 
{
public:
    uint64() {}
    uint64(const std::string& data):uintN(data) {}
};

class uint128 : public uintN<128> 
{
public:
    uint128() {}
    uint128(const std::string& data):uintN(data) {}
};

class uint256 : public uintN<256> 
{
public:
    uint256() {}
    uint256(const std::string& data):uintN(data) {}
};

}//namespace
#endif




