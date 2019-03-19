/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_BYTES_H__
#define __CPP_SSZ_BYTES_H__

#include "Common.h"
namespace ssz {

    class bytes: private std::vector<byte>
    {
        public:
            using std::vector<byte>::size; 
            using std::vector<byte>::begin;
            using std::vector<byte>::end;
            using std::vector<byte>::push_back;
            using std::vector<byte>::insert;
            using std::vector<byte>::operator[]; 
            using std::vector<byte>::const_iterator; 
            using std::vector<byte>::resize; 

            bytes() {}
            bytes(const std::string& v) 
            { 
                for(byte c : v) this->push_back(c);
            }

            // encode/decode section
            void from_bytes(bytes& data, byteorder bo);
            bytes to_bytes(unsigned int size, byteorder bo);

            // operators
            bool operator==(const bytes& b)
            {
                return std::equal(b.begin(), b.end(), this->begin());
            }
    };

    void bytes::from_bytes(bytes& data, byteorder bo)
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
        for(int i=0; i< prefix; i++)
            this->push_back(data[BYTES_PER_LENGTH_PREFIX+i]);
    }

    bytes bytes::to_bytes(unsigned int size, byteorder bo)
    {
        unsigned int prefix = size;
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
        temp.insert(temp.end(), this->begin(), this->end());
        return bytes(temp); 
    }

}//namespace
#endif
