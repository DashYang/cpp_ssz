#include "cpp_ssz.h"

//template body

template <class T>
T* cpp_ssz_codec<T>::from_bytes(byte* bytes, byteorder bo)
{

	return NULL;
}

template <>
byte* cpp_ssz_codec<bool>::to_bytes(unsigned int size, byteorder bo)
{
	int ret_size = (size+3) * m_count;
	byte* ret = new byte[ret_size];
	int prefix = 8388608 + 1;
	for(int i=0; i<m_count; i++) {
		ret[0+4*i] = (byte)((prefix & 0x00ff0000) >> 16);
		ret[1+4*i] = (prefix >> 8) & 0xff;
		ret[2+4*i] = (prefix >> 0) & 0xff;
		if(m_value[i])
			ret[3+4*i] = 0x01;
		else
			ret[3+4*i] = 0x00;
	}
	return ret;
}

template <class T>
byte* cpp_ssz_codec<T>::to_bytes(unsigned int size, byteorder bo)
{
	int ret_size = (size+3) * m_count;
	byte* ret = new byte[ret_size];
	for(int i=0; i<m_count; i++) {
		memcpy(ret+ i * (size+3),
		m_value[i].to_bytes(size,bo),
		size+3);
	}
	return ret;
}
