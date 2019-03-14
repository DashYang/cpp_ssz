/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include "Common.h"

namespace ssz {

template<unsigned int N>
class uintN 
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

	uintN(const std::string& data) 
	{ 
        assert(!(N % 8));
		m_size = N / 8;
        unsigned int i = 0;
        if (data.size() >= 2 && data.substr(0, 2) == "0x")
            i = 2;

        for (; i < data.length(); i += 2) {
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
    //assert(data.size() >= m_size+3);
	int prefix = 0;
    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;
    for(int i=0; i< prefix; i++)
        m_data.push_back(data[3+i]);
}

template<unsigned int N>
bytes uintN<N>::to_bytes(unsigned int size, byteorder bo)
{
	int prefix = 8388608 + m_size;
    bytes temp;
    temp.push_back((prefix & 0x00ff0000) >> 16);
	temp.push_back((prefix >> 8) & 0xff);
	temp.push_back((prefix >> 0) & 0xff);
    temp.insert(temp.end(), m_data.begin(), m_data.end());
	return bytes(temp); 
}


class uint256 : public uintN<256> 
{
public:
    typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>> uint_data;
    uint256() {}
    uint256(const std::string& data):uintN(data) {}
};

}
#endif




