/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_TUPLE_H__
#define __CPP_SSZ_TUPLE_H__

#include "Common.h"

namespace ssz {
template<class T, unsigned int N>
class Tuple
{
protected:
	unsigned int m_size;
	std::array<T, N> m_data;
public:
	Tuple() 
	{ 
	}

	~Tuple()
	{
		m_data.empty();
	}

	unsigned int size() const { return m_data.size(); }
	std::array<T, N>& data() { return m_data; }
	const std::array<T, N>& get_data_array() const { return m_data; }

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);
/*
// operators
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
*/
    T& operator [](int idx) {
        return m_data[idx];
    }
};

template<class T, unsigned int N>
void Tuple<T, N>::from_bytes(bytes& data, byteorder bo)
{
/*
	int prefix = 0;
    prefix |= data[0] << 16;
	prefix |= data[1] << 8;
	prefix |= data[2] << 0;
    prefix -= 8388608;

    for(int i=0; i< prefix; i++)
        m_data[i] = data[3+i];
*/
}

template<class T, unsigned int N>
bytes Tuple<T, N>::to_bytes(unsigned int size, byteorder bo)
{

    std::vector<byte> temp;
    for (unsigned int i=0; i < N; i++) {
        bytes t = m_data[i].to_bytes(m_data[i].size(), little);
        temp.insert(temp.end(), t.begin(), t.end()); 
    }

	return bytes(temp); 
}
}//namespace
#endif
