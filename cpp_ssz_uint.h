/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_UINT_H__
#define __CPP_SSZ_UINT_H__

#include "Common.h"


template<unsigned int N>
class uintN 
{
    typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<N, N, boost::multiprecision::unsigned_magnitude, boost::multiprecision::unchecked, void>> uint_data;
protected:
	unsigned int m_size;
    uint_data m_data;
public:
	uintN() 
	{ 
        assert(!(N % 8));
		m_size = N % 8;
        m_data = 0;
	}

	uintN(unsigned int data) 
	{ 
        assert(!(N % 8));
		m_size = N % 8;
        m_data = data;
	}

	~uintN()
	{

	}

	unsigned int size() const { return m_size; }
	const uint_data data() { return m_data; }
	//const std::array<byte, N>& get_data_array() const { return m_data; }

// encode/decode section
    void from_bytes(const bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
/*
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
*/
};

template<unsigned int N>
void uintN<N>::from_bytes(const bytes& data, byteorder bo)
{
/*
	int prefix = 0;
    assert(data.size() >= N+3);

    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;

    for(int i=0; i< prefix; i++)
        m_data[i] = data[3+i];
*/
}

template<unsigned int N>
bytes uintN<N>::to_bytes(unsigned int size, byteorder bo)
{
	int prefix = 8388608 + m_size;
    bytes temp;
    temp.push_back((prefix & 0x00ff0000) >> 16);
	temp.push_back((prefix >> 8) & 0xff);
	temp.push_back((prefix >> 0) & 0xff);
 //   temp.insert(temp.end(), m_data.begin(), m_data.end());
	return bytes(temp); 
}


class uint256 : public uintN<256> 
{
public:
    uint256() {}
    uint256(unsigned int data):uintN(data) {}
/*
    bytes8(std::string& data):bytesN(data) {}
*/
};
#endif




