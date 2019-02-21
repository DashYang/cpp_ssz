# cpp_ssz
----------
Simple serialization for ethereum (cpp version)

### SSZ SPEC
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md


### Build & Run
1. Install g++ for compile
2. make
3. ./test
```
[dog, horse]
80 00 0e - enc3b(all)
80 00 0e 80 00 03 - enc3b for key
80 00 0e 80 00 03 64 6f 67 - write dog
80 00 0e 80 00 03 64 6f 67 80 00 05 - enc3b for value
80 00 0e 80 00 03 64 6f 67 80 00 05 68 6f 72 73 65 - write horse
```
