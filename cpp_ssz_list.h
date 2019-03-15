/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_LIST_H__
#define __CPP_SSZ_LIST_H__

#include "Common.h"

namespace ssz {
template<class T>
class List: public cpp_ssz_types
{
protected:
	unsigned int m_size;
	std::vector<T> m_data;
public:
	List() 
	{ 
	}

	~List()
	{
		m_data.empty();
	}

	unsigned int size() const { return m_data.size(); }
	std::vector<T>& data() { return m_data; }

// encode/decode section
    void from_bytes(const bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);
/*
// operators
	bool operator==(const bytesN<N>& b)
	{
	     return this->m_data == b.get_data_array();
	}
*/
};

template<class T>
void List<T>::from_bytes(const bytes& data, byteorder bo)
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

template<class T>
bytes List<T>::to_bytes(unsigned int size, byteorder bo)
{

    bytes temp1;
    for (unsigned i=0; i < m_data.size(); i++) {
        bytes t = m_data[i].to_bytes(m_data[i].size(), little);
        temp1.insert(temp1.end(), t.begin(), t.end()); 
    }

	unsigned int prefix = SSZ_PREFIX + temp1.size();
    bytes temp;
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
    temp.insert(temp.end(), temp1.begin(), temp1.end());
	return bytes(temp); 
}
}//namespace
#endif
