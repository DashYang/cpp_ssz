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
#include <ethash/ethash.hpp>
#include <ethash/keccak.hpp>
#include <queue>

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
    ethash::hash256 merkleize(List<bytes32>& in) {
        List<bytes32> chunks = in;
        int chunks_len = chunks.size(); 

        if( (chunks_len & (chunks_len-1)) != 0) {//not power of 2
            int power = 1;
            bytes32 zero; //default initialized 0
            while(power < chunks_len)
                power*=2;
            for(int i=0; i<power-chunks_len; i++)
                chunks.push_back(zero);
        }
        std::queue<ethash::hash256> myq;

        for(int i=0; i< chunks.size(); i += 2) {
            bytes a(chunks[i+0].to_bytes(4,little));
            bytes b(chunks[i+1].to_bytes(4,little));
            a.insert(a.end(), b.begin(), b.end());
            ethash::hash256 h = ethash::keccak256(a.data(), a.size());
            myq.push(h);
        }

        while(myq.size()!=1) {
            ethash::hash256 h1 = myq.front();
            myq.pop();
            ethash::hash256 h2 = myq.front();
            myq.pop();
            bytes a(h1.bytes,32);
            bytes b(h2.bytes,32);
            a.insert(a.end(), b.begin(), b.end());
            ethash::hash256 h = ethash::keccak256(a.data(), a.size());
            myq.push(h);
        }

        ethash::hash256 root = myq.front();
        myq.pop();
        return ethash::hash256(root);
    } 


    //mix_in_length: Given a Merkle root root and a length length ("uint256" little-endian serialization) return hash(root + length).
    ethash::hash256 mix_in_length(ethash::hash256 root, uint256 length) {
        bytes concat(root.bytes,32);
        bytes little_endian = length.to_bytes(4, little);
        concat.insert(concat.end(), little_endian.begin(), little_endian.end());
        return ethash::keccak256(concat.data(), concat.size());
    }

}

#endif

