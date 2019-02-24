# cpp_ssz
Simple serialization for ethereum (cpp version)

### SSZ SPEC
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md


### Build & Run
1. Install g++ for compile
2. make
3. ./test_bin

### Developemt status
uintN
 - assign
 - encode

bytesN
 - assign
 - encode

### Usage as of now
```
	uint8 b = 255;
	uint8 c(257);
	uint256 e = 0xabcdef01;
	bytes4 enc4 = "abcdefgh";
	bytes8 enc8 = bytes8("abcdefghijklmnop");
```
