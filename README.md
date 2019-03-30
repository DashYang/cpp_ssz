# cpp_ssz
[![Build Status](https://travis-ci.org/NAKsir-melody/cpp_ssz.svg?branch=master)](https://travis-ci.org/NAKsir-melody/cpp_ssz)
----------------

This is c++ version simple serialization library to support ethereum 2.0 (PoC, cpp version)

## SSZ SPEC(WIP)
official spec: https://github.com/ethereum/eth2.0-specs/blob/dev/specs/simple-serialize.md

commit history: https://github.com/ethereum/eth2.0-specs/commits/dev/specs/simple-serialize.md

discuss1(official): https://notes.ethereum.org/QF8jgOQbRTWUhK1zoi8D4Q#

discuss2(local, cpp): https://hackmd.io/IL-M0meORQm7erZGjzHzkg

## milestones
1. MVP for most fuctionality (as of now)
2. match terminology with aleth project (https://github.com/ethereum/aleth)
2. Integrate to aleth

### Build
1. mkdir build
2. cd build
3. cmake ../
4. make

### ssz::Bool Usage
```
//encoding
        Bool testval(true);
        bytes enc = testval.to_bytes(1,little);
//decoding
        Bool dec;
        dec.from_bytes(enc, little);
```
### ssz::bytes Usage
```
//encoding
        bytes testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
//decoding
        bytes dec;
        dec.from_bytes(enc, little);
```
### ssz::bytesN Usage
```
// bytes[32, 48, 96]
//encoding
        bytes32 testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);

//decoding
        bytes32 dec;
        dec.from_bytes(enc, little);
```

### ssz::uintN Usage
```
//uint[8, 16, 32, 64, 128, 256]
//encoding
        u64 a(18446744073709551615);
        uint64 testval(a);
        bytes enc = testval.to_bytes(testval.size(),little);

//decoding
        uint64 dec;
        dec.from_bytes(enc, little);
```

### ssz::List Usage
```
//list: ordered variable-length homogenous collection of values
//encoding
        List<uint32> testval;
        uint32 a0(1);
        uint32 a1(2);
        testval.push_back(a0);
        testval.push_back(a1);
        bytes enc = testval.to_bytes(a0.size(), little);

//decoding
        List<uint32> dec;
        dec.from_bytes(enc, little);
```
### ssz::Vector Usage
```
//vector: ordered fixed-length homogeneous collection of values
//encoding
    Vector<uint256, 3> a;
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);
    a[0] = testval;
    a[1] = testval;
    a[2] = testval;

    bytes enc = a.to_bytes(0, little);
```

### ssz::container Usage
```
//container: ordered heterogenous collection of values
//encoding
    bytes b("abcdefg");
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);

    Container<bytes32,uint256> a; 
    a.push_back(std::make_pair(bytes32(b),testval));
    bytes enc = a.to_bytes(0, little);
```

### Utilize functions Usage
```
//pack
    List<Bool> testval;
    bytes packed = pack(testval);
    
//merkleize
    List<bytes32> testval;
    ethash::hash256 roothash = merkleize(testval);
    bytes result(roothash.bytes,32);

//mix_in_length
    int8_t data[4] = {0x1,0x2,0x3,0x4};
    ethash::hash256 root = ethash::keccak256(data, 4);
    uint256 length;

    ethash::hash256 mix = mix_in_length(root, length);
    bytes result(mix.bytes,32);
```
