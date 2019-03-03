#include "cpp_ssz.h"

//template body

template <class T, unsigned int N>
T* cpp_ssz_codec<T,N>::from_bytes(byte* bytes, byteorder bo)
{

	return NULL;
}

template <>
byte* cpp_ssz_codec<bool,1>::to_bytes(unsigned int size, byteorder bo)
{
	byte* dst = new byte[4];
	int prefix = 8388608 + 1;
	dst[0] = (byte)((prefix & 0x00ff0000) >> 16);
	dst[1] = (prefix >> 8) & 0xff;
	dst[2] = (prefix >> 0) & 0xff;
	if(m_value)
		dst[3] = 0x01;
	else
		dst[3] = 0x00;
	return dst;
}

template <class T, unsigned int N>
byte* cpp_ssz_codec<T,N>::to_bytes(unsigned int size, byteorder bo)
{
	return m_value.to_bytes(size,bo);
}
