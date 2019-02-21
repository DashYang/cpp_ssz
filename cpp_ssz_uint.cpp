#include "cpp_ssz_uint.h"


template <unsigned int N>
uint<N>* uint<N>::from_bytes(byte* bytes, byteorder bo)
{
	//decode somthing
	//update m_value
	return this; 
}

template <unsigned int N>
byte* uint<N>::to_bytes(unsigned int size, byteorder bo)
{
	int len = size;
	int prefix = 8388608 + len;
	byte* enc = new byte[3 + size];
	enc[0] = (byte)((prefix & 0x00ff0000) >> 16);
	enc[1] = (prefix >> 8) & 0xff;
	enc[2] = (prefix >> 0) & 0xff;
	memcpy(enc + 3, m_value, size);
	return enc; 
}

template byte* uint<8>::to_bytes(unsigned int size, byteorder bo);

template uint<8>* uint<8>::from_bytes(byte* bytes, byteorder bo);

template byte* uint<256>::to_bytes(unsigned int size, byteorder bo);

template uint<256>* uint<256>::from_bytes(byte* bytes, byteorder bo);
