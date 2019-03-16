# cpp_ssz
Simple serialization for ethereum (cpp version)

### SSZ SPEC
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md

### Build
1. mkdir build
2. cd build
3. cmake ../
4. make

### Run tests
test_bool  
test_uintN
test_bytesN  
test_tuple  
test_container  
test_list  

### bool Usage
```
        Bool testval(true);
        bytes enc = testval.to_bytes(1,little);
        print_hex(enc);
```
### bytesN Usage
```
//fixed length type
        bytes8 testval(s_over);
        bytes enc = testval.to_bytes(8,little);
        print_hex(enc);

        bytes8 dec;
        dec.from_bytes(enc, little);

//variable length
        bytesN<16> testval(s_under);
        bytes enc = testval.to_bytes(16,little);
        print_hex(enc);

        bytesN<16> dec;
        dec.from_bytes(enc, little);
```

### uintN Usage
```
//fixed length type
    uint256 testval("0x16b3dfaec148fb1bb2b066f10ec285e7c9bf402ab32aa78a5d38e34566810cd2");
    bytes enc = testval.to_bytes(256/8,little);

    uint256 dec;
    dec.from_bytes(enc, little);

//variable length
    uintN<264> 
    ...
```

### tuple Usage
```
//tuple: ordered fixed-length homogeneous collection of values
//[type, N]
    Tuple<uint256, 3> a;
    a[0] = testval1;
    a[1] = testval2;
    a[2] = testval3;

    bytes enc = a.to_bytes(0, little);
```

### list Usage
```
//list: ordered variable-length homogenous collection of values
//[type]
    List<bytes8> a;
    a.data().push_back(bytes8(b_over));
    a.data().push_back(bytes8(b_fit));
    a.data().push_back(bytes8(b_under));
    bytes enc = a.to_bytes(0, little);

    List<uint256> b;
    b.data().push_back(testval1);
    b.data().push_back(testval2);
    b.data().push_back(testval3);
    bytes enc1 = b.to_bytes(0, little);
```

### container Usage
```
//container: ordered heterogenous collection of values
    Container<bytes8,uint256> a; 
    a.data().push_back(std::make_pair(bytes8(b_over),testval1));
    bytes enc = a.to_bytes(0, little);
```
