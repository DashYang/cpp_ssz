/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_LIST_H__
#define __CPP_SSZ_LIST_H__

#include "Common.h"
#include "cpp_ssz_bytes.h"

namespace ssz {

#if 0
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

    T a;
    for(int i=0; i< prefix ; i += a.size()) {
        bytes b(data, i, a.size());
        a.from_bytes(b, bo);
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
#else
template<class T>
class List:private std::vector<T>
{
public:
    using std::vector<T>::size; 
    using std::vector<T>::begin;
    using std::vector<T>::end;
    using std::vector<T>::push_back;
    using std::vector<T>::insert;
    using std::vector<T>::operator[]; 

// encode/decode section
    void from_bytes(bytes& data, byteorder bo);
	bytes to_bytes(unsigned int size, byteorder bo);

// operators
	bool operator==(const List<T>& b)
	{
	     return std::equal(b.begin(), b.end(), this->begin());
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

    T a;
    bytes b;
    b.resize(a.size());
    for(int i=0; i< prefix ; i += a.size()) {
        memcpy(&b[0], &data[4+i], a.size());
        a.from_bytes(b, bo);
        this->push_back(a);
    }
}

template<class T>
bytes List<T>::to_bytes(unsigned int size, byteorder bo)
{

    bytes temp1;
    for (unsigned i=0; i < this->size(); i++) {
        bytes t = this->at(i).to_bytes(this->at(i).size(), little);
        temp1.insert(temp1.end(), t.begin(), t.end()); 
    }

	unsigned int prefix = temp1.size();
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
#endif
}//namespace
#endif
