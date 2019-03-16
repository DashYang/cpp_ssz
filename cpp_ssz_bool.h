/*
	This file is part of cpp_ssz.
    @author SigmoiD <alphabet@hotmail.co.kr>
*/ 

#ifndef __CPP_SSZ_BOOL_H__
#define __CPP_SSZ_BOOL_H__

#include "Common.h"

namespace ssz {
class Bool 
{
	unsigned int m_size;
    bool m_data;
public:
	Bool() 
	{ 
		m_size = 1;
        m_data = false;
	}
	Bool(const bool& value) 
	{ 
		m_size = 1;
        m_data = value;
	}
	unsigned int size() const { return m_size; }
    bool data() const { return m_data; }

// encode/decode section
    void from_bytes(bytes& data, byteorder bo)
    {
        assert(data[0] == 0x01 || data[0] == 0x00 );
        if(data[0] == 0x01)
            m_data =  true;
        else
            m_data = false;
    }

    bytes to_bytes(unsigned int size, byteorder bo)
    {
        bytes temp;
        if(m_data == true)  
            temp.push_back(0x01);
        else
            temp.push_back(0x00);
	    return bytes(temp); 
    }
// operators
	bool operator==(const Bool& b)
	{
	     return this->m_data == b.data();
	}
	bool operator==(const bool b)
	{
	     return this->m_data == b;
	}
};
}//namespace
#endif
