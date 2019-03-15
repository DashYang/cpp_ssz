/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_CONTAINER_H__
#define __CPP_SSZ_CONTAINER_H__

#include "Common.h"

namespace ssz {

template<class K, class V>
class Container: public cpp_ssz_types
{
protected:
	unsigned int m_size;
    std::vector<std::pair<K, V>> m_data;
public:
	Container() 
	{ 
	}

	~Container()
	{
		m_data.empty();
	}

	unsigned int size() const { return m_data.size(); }
    std::vector<std::pair<K, V>>& data() { return m_data; }

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


template<class K, class V>
void Container<K, V>::from_bytes(const bytes& data, byteorder bo)
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

template<class K, class V>
bytes Container<K, V>::to_bytes(unsigned int size, byteorder bo)
{

    bytes temp1;
    for (unsigned i=0; i < m_data.size(); i++) {
        bytes t1 = m_data[i].first.to_bytes(m_data[i].first.size(), little);
        temp1.insert(temp1.end(), t1.begin(), t1.end()); 
        bytes t2 = m_data[i].second.to_bytes(m_data[i].second.size(), little);
        temp1.insert(temp1.end(), t2.begin(), t2.end()); 
    }

	int prefix = 8388608 + temp1.size();
    bytes temp;
    temp.push_back((prefix & 0x00ff0000) >> 16);
	temp.push_back((prefix >> 8) & 0xff);
	temp.push_back((prefix >> 0) & 0xff);
    temp.insert(temp.end(), temp1.begin(), temp1.end());
	return bytes(temp); 
}



}
#endif
