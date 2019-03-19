/*
   This file is part of cpp_ssz.
   @author SigmoiD <alphabet@hotmail.co.kr>
 */ 

#ifndef __CPP_SSZ_UTIL_H__
#define __CPP_SSZ_UTIL_H__

#include "Common.h"
#include "cpp_ssz_bool.h"
#include "cpp_ssz_uint.h"
#include "cpp_ssz_bytes.h"
namespace ssz {

    //pack: Given ordered objects of the same basic type, serialize them, pack them into BYTES_PER_CHUNK-byte chunks, right-pad the last chunk with zero bytes, and return the chunks.
    template <class T>
        bytes pack(List<T> s) {
            bytes temp = s.to_bytes(0,little); 
            int size = temp.size();
            if(size % BYTES_PER_CHUNK) {
                int new_size = ((size+BYTES_PER_CHUNK-1)/BYTES_PER_CHUNK)*BYTES_PER_CHUNK;
                for(int i = 0; i < new_size-size; i++)
                    temp.push_back(0x00);
            }
            return bytes(temp);
        }

    template bytes pack(List<Bool>);
    template bytes pack(List<uint8>);
    template bytes pack(List<uint16>);
    template bytes pack(List<uint32>);
    template bytes pack(List<uint64>);
    template bytes pack(List<uint128>);
    template bytes pack(List<uint256>);

    //merkleize: Given ordered BYTES_PER_CHUNK-byte chunks, if necessary append zero chunks so that the number of chunks is a power of two, Merkleize the chunks, and return the root.

    //mix_in_length: Given a Merkle root root and a length length ("uint256" little-endian serialization) return hash(root + length).


}
#endif

