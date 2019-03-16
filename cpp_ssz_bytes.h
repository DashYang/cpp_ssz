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

	bytesN(bytes& value) 
	{ 
        assert(!(N % 8));
		m_size = N;
        std::fill(m_data.begin(), m_data.end(), 0);
        if( value.size() <= N) 
            std::copy_n(value.data().begin(), value.data().size(), m_data.begin());
        else
            std::copy_n(value.data().begin(), N , m_data.begin());
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
	std::array<byte, N> data() { return m_data; }
	const std::array<byte, N>& get_data_array() const { return m_data; }

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
};

template<unsigned int N>
void bytesN<N>::from_bytes(bytes& data, byteorder bo)
{
	int prefix = 0;
    assert(data.size() >= N);

    if(bo == little) {
        prefix |= data[3] << 24;
        prefix |= data[2] << 16;
        prefix |= data[1] << 8;
        prefix |= data[0] << 0;
    }
    else {
        prefix |= data[0] << 24;
        prefix |= data[1] << 16;
        prefix |= data[2] << 8;
        prefix |= data[3] << 0;
    }

    for(int i=0; i< prefix; i++)
        m_data[i] = data[BYTES_PER_LENGTH_PREFIX+i];
}

template<unsigned int N>
bytes bytesN<N>::to_bytes(unsigned int size, byteorder bo)
{
	unsigned int prefix = m_size;
    std::vector<byte> temp;
    if(bo == little) {
        temp.push_back((prefix >> 0) & 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 24)& 0xff);
    }
    else {
        temp.push_back((prefix >> 24)& 0xff);
        temp.push_back((prefix >> 16)& 0xff);
        temp.push_back((prefix >> 8) & 0xff);
        temp.push_back((prefix >> 0) & 0xff);
    }
    temp.insert(temp.end(), m_data.begin(), m_data.end());
	return bytes(temp); 
}


class bytes32 : public bytesN<32> 
{
public:
    bytes32() {}
    bytes32(bytes& data):bytesN(data) {}
    bytes32(const std::string& data):bytesN(data) {}
};

class bytes48 : public bytesN<48> 
{
public:
    bytes48() {}
    bytes48(bytes& data):bytesN(data) {}
    bytes48(const std::string& data):bytesN(data) {}
};

class bytes96 : public bytesN<96> 
{
public:
    bytes96() {}
    bytes96(bytes& data):bytesN(data) {}
    bytes96(const std::string& data):bytesN(data) {}
};


}//namespace
#endif
