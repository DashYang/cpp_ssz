# cpp_ssz
Simple serialization for ethereum (cpp version)

### SSZ SPEC
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md


### Build & Run
1. Install g++ for compile
2. make
3. ./test

### Developemt status
1. Define user types
uintN
bytesN

2. cpp_ssz as a template encoder
```
cpp_ssz_codec<bool> codec;
cpp_ssz_codec<uint8> codec1;
cpp_ssz_codec<bytes4> codec2;
```
3. humbly support arrays
```
bytes4 list[2] = {"abcd", "efgh"};
cpp_ssz_codec<bytes4> codec4;
codec4.m_value = list;
codec4.m_count = 2;
byte* enc4 = codec4.to_bytes(list[0].size(),little);
```

### Test run result  as of now
```
/////////bool
//false;
80 00 01 00 
//true;
80 00 01 01 

/////////uint
//uint8 a(255);
80 00 01 ff 

/////////bytes
//byte4
80 00 04 61 62 63 64 

/////////list
//{true,false}
80 00 01 01 80 00 01 00 
//{"abcd","efgh"}
80 00 04 61 62 63 64 80 00 04 65 66 67 68 

```
