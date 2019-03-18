/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_CONTAINER_H__
#define __CPP_SSZ_CONTAINER_H__

#include "Common.h"

namespace ssz {

    template<class K, class V>
        class Container: private std::vector<std::pair<K, V>>
    {
        public:
            using std::vector<std::pair<K, V>>::size; 
            using std::vector<std::pair<K, V>>::begin;
            using std::vector<std::pair<K, V>>::end;
            using std::vector<std::pair<K, V>>::push_back;
            using std::vector<std::pair<K, V>>::insert;
            using std::vector<std::pair<K, V>>::operator[]; 
            using std::vector<std::pair<K, V>>::const_iterator; 
            using std::vector<std::pair<K, V>>::resize; 

            // encode/decode section
            void from_bytes(bytes& data, byteorder bo);
            bytes to_bytes(unsigned int size, byteorder bo);
    };


    template<class K, class V>
        void Container<K, V>::from_bytes(bytes& data, byteorder bo)
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

            K a1;
            V a2;
            bytes b1;
            b1.resize(a1.size());
            bytes b2;
            b2.resize(a2.size());
            for(int i=0; i< prefix ; i += a1.size() + a2.size()) {
                memcpy(&b1[0], &data[4+i], a1.size());
                a1.from_bytes(b1, bo);
                memcpy(&b2[0], &data[4+i+a1.size()], a2.size());
                a2.from_bytes(b2, bo);
                this->push_back(std::make_pair(a1,a2));
            }
        }

    template<class K, class V>
        bytes Container<K, V>::to_bytes(unsigned int size, byteorder bo)
        {

            bytes temp1;
            for (unsigned i=0; i < this->size(); i++) {
                bytes t1 = this->at(i).first.to_bytes(this->at(i).first.size(), little);
                temp1.insert(temp1.end(), t1.begin(), t1.end()); 
                bytes t2 = this->at(i).second.to_bytes(this->at(i).second.size(), little);
                temp1.insert(temp1.end(), t2.begin(), t2.end()); 
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

}//namespace
#endif
