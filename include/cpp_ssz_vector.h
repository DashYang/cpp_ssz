/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_TUPLE_H__
#define __CPP_SSZ_TUPLE_H__

#include "Common.h"

namespace ssz {

    template<class T, unsigned int N>
        class Vector: private std::array<T, N>
    {
        public:
            using std::array<T, N>::size; 
            using std::array<T, N>::begin;
            using std::array<T, N>::end;
            using std::array<T, N>::at;
            using std::array<T, N>::operator[]; 

            // encode/decode section
            void from_bytes(bytes& data, byteorder bo);
            bytes to_bytes(unsigned int size, byteorder bo);

            // operators
            bool operator==(Vector<T, N>& b)
            {
                return std::equal(b.begin(), b.end(), this->begin());
            }
    };

    template<class T, unsigned int N>
        void Vector<T, N>::from_bytes(bytes& data, byteorder bo)
        {
            T a;
            bytes b;
            b.resize(a.size());
            for(int i=0; i< N ; i++) {
                memcpy(&b[0], &data[i*a.size()], a.size());
                a.from_bytes(b, bo);
                this->at(i) = a;
            }
        }

    template<class T, unsigned int N>
        bytes Vector<T, N>::to_bytes(unsigned int size, byteorder bo)
        {

            bytes temp;
            for (unsigned int i=0; i < N; i++) {
                bytes t = this->at(i).to_bytes(this->at(i).size(), bo);
                temp.insert(temp.end(), t.begin(), t.end()); 
            }
            return bytes(temp); 
        }

}//namespace
#endif
