/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_LIST_H__
#define __CPP_SSZ_LIST_H__

#include "Common.h"

namespace ssz {
template<class T>
class List
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
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
    void push_back(T a) {
        return m_data.push_back(a);
    }
};

template<class T>
void List<T>::from_bytes(bytes& data, byteorder bo)
{
	int prefix = 0;

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

    T b;
    for(int i=0; i< prefix / b.size(); i++) {
        T a(data[4+b.size() * i]);
        m_data.push_back(a);
    }

}

template<class T>
bytes List<T>::to_bytes(unsigned int size, byteorder bo)
{

    std::vector<byte> temp1;
    for (unsigned i=0; i < m_data.size(); i++) {
        bytes t = m_data[i].to_bytes(m_data[i].size(), little);
        temp1.insert(temp1.end(), t.data().begin(), t.data().end()); 
    }

	unsigned int prefix = temp1.size();
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
    temp.insert(temp.end(), temp1.begin(), temp1.end());
	return bytes(temp); 
}
}//namespace
#endif
