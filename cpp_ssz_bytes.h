/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_BYTES_H__
#define __CPP_SSZ_BYTES_H__

#include "Common.h"

namespace ssz {

template<unsigned int N>
class bytesN
{
protected:
	unsigned int m_size;
	std::array<byte, N> m_data;
public:
	bytesN() 
	{ 
        assert(!(N % 8));
        std::fill(m_data.begin(), m_data.end(), 0);
		m_size = N;
	}

	bytesN(const bytes& value) 
	{ 
        assert(!(N % 8));
		m_size = N;
        std::fill(m_data.begin(), m_data.end(), 0);
        if( value.size() <= N) 
            std::copy_n(value.begin(), value.size(), m_data.begin());
        else
            std::copy_n(value.begin(), N , m_data.begin());
	}

	bytesN(const std::string& value) 
	{ 
        assert(!(N % 8));
		m_size = N;
        std::fill(m_data.begin(), m_data.end(), 0);
        if( value.size() <= N) 
            std::copy_n(value.begin(), value.size(), m_data.begin());
        else
            std::copy_n(value.begin(), N , m_data.begin());
	}

	~bytesN()
	{
		m_data.empty();
	}

	unsigned int size() const { return m_size; }
	const unsigned char* data() { return m_data.data(); }
	const std::array<byte, N>& get_data_array() const { return m_data; }

// encode/decode section
    void from_bytes(const bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
};

template<unsigned int N>
void bytesN<N>::from_bytes(const bytes& data, byteorder bo)
{
	int prefix = 0;
    assert(data.size() >= N+3);

    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;

    for(int i=0; i< prefix; i++)
        m_data[i] = data[3+i];
}

template<unsigned int N>
bytes bytesN<N>::to_bytes(unsigned int size, byteorder bo)
{
	int prefix = 8388608 + m_size;
    bytes temp;
    temp.push_back((prefix & 0x00ff0000) >> 16);
	temp.push_back((prefix >> 8) & 0xff);
	temp.push_back((prefix >> 0) & 0xff);
    temp.insert(temp.end(), m_data.begin(), m_data.end());
	return bytes(temp); 
}


class bytes8 : public bytesN<8> 
{
public:
    bytes8() {}
    bytes8(bytes& data):bytesN(data) {}
    bytes8(std::string& data):bytesN(data) {}
};

}
#endif
