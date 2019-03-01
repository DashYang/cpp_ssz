#include "cpp_ssz_bool.h"

bool BOOL::from_bytes(byte* bytes, byteorder bo)
{
	return bytes[3]? true:false;
}

byte* BOOL::to_bytes(unsigned int size, byteorder bo)
{
	int len = size;
	int prefix = 8388608 + len;
	byte* enc = new byte[3 + size];
	enc[0] = (byte)((prefix & 0x00ff0000) >> 16);
	enc[1] = (prefix >> 8) & 0xff;
	enc[2] = (prefix >> 0) & 0xff;
	enc[3] = m_value? 0x01 : 0x00; 
	return enc; 
}

