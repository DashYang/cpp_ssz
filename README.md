# cpp_ssz
Simple serialization for ethereum (cpp version)

### SSZ SPEC
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md

### Build
1. mkdir build
2. cd build
3. cmake ../
4. make

### bool Usage
```
//encoding
        Bool testval(true);
        bytes enc = testval.to_bytes(1,little);
//decoding
        Bool dec;
        dec.from_bytes(enc, little);
```
### bytes Usage
```
//encoding
        bytes testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);
//decoding
        bytes dec;
        dec.from_bytes(enc, little);
```
### bytesN Usage
```
// bytes[32, 48, 96]
//encoding
        bytes32 testval("hello");
        bytes enc = testval.to_bytes(testval.size(),little);

//decoding
        bytes32 dec;
        dec.from_bytes(enc, little);
```

### uintN Usage
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

### list Usage
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
### tuple Usage
```
//tuple: ordered fixed-length homogeneous collection of values
//encoding
    Tuple<uint256, 3> a;
    u256 data("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    uint256 testval(data);
    a[0] = testval;
    a[1] = testval;
    a[2] = testval;

    bytes enc = a.to_bytes(0, little);
```


### container Usage
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
