#include "cpp_ssz_bytes.h"

template <unsigned int N>
bytes<N>* bytes<N>::from_bytes(byte* bytes, byteorder bo)
{
	//decode somthing
	//update m_value
	return this; 
}

template <unsigned int N>
byte* bytes<N>::to_bytes(unsigned int size, byteorder bo)
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

template byte* bytes<4>::to_bytes(unsigned int size, byteorder bo);

template bytes<4>* bytes<4>::from_bytes(byte* bytes, byteorder bo);

template byte* bytes<8>::to_bytes(unsigned int size, byteorder bo);

template bytes<8>* bytes<8>::from_bytes(byte* bytes, byteorder bo);
