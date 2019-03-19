/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_BYTESN_H__
#define __CPP_SSZ_BYTESN_H__

#include "Common.h"
#include "cpp_ssz_bytes.h"

namespace ssz {

    template<unsigned int N>
        class bytesN: private std::array<byte, N>
    {
        public:
            using std::array<byte, N>::size; 
            using std::array<byte, N>::begin;
            using std::array<byte, N>::end;
            using std::array<byte, N>::at;
            using std::array<byte, N>::operator[]; 
            bytesN() 
            { 
                assert(!(N % 8));
                std::fill(this->begin(), this->end(), 0);
            }

            bytesN(bytes& value) 
            { 
                assert(!(N % 8));
                std::fill(this->begin(), this->end(), 0);
                if( value.size() <= N) 
                    std::copy_n(value.begin(), value.size(), this->begin());
                else
                    std::copy_n(value.begin(), N , this->begin());
            }

            bytesN(const std::string& v) 
            { 
                std::fill(this->begin(), this->end(), 0);
                if( v.size() <= N) 
                    for(std::string::size_type i = 0; i < v.size(); ++i) this->at(i) =v[i];
                else
                    for(std::string::size_type i = 0; i < N; ++i) this->at(i) =v[i];
            }

            // encode/decode section
            void from_bytes(bytes& data, byteorder bo);
            bytes to_bytes(unsigned int size, byteorder bo);

            // operators
            bool operator==(bytesN<N>& b)
            {
                return std::equal(b.begin(), b.end(), this->begin());
            }
    };

    template<unsigned int N>
        void bytesN<N>::from_bytes(bytes& data, byteorder bo)
        {
            for(int i=0; i< N; i++)
                this->at(i) = data[i];
        }

    template<unsigned int N>
        bytes bytesN<N>::to_bytes(unsigned int size, byteorder bo)
        {
            bytes temp;
            temp.insert(temp.end(), this->begin(), this->end());
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
