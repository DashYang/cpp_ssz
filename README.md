# cpp_ssz
Simple serialization (cpp version)

[dog, horse]
```
80 00 0e - enc3b(all)
80 00 0e 80 00 03 - enc3b for key
80 00 0e 80 00 03 64 6f 67 - write dog
80 00 0e 80 00 03 64 6f 67 80 00 05 - enc3b for value
80 00 0e 80 00 03 64 6f 67 80 00 05 68 6f 72 73 65 - write horse
```
