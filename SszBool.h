#ifndef __SSZ_BOOL_H__
#define __SSZ_BOOL_H__
#include "SszBase.h"

class Bool : public DataObject, ssz
{
	bool m_value;
public:
	Bool():DataObject(type_BOOL),m_value(false){}
	Bool(bool value):DataObject(type_BOOL)
	{
		m_value = value;
	}

	size_t len()
	{
		return size_t(1);
	}

	byte* to_bytes(size_t size, ByteOrder bo) {
		byte* ret = new byte[size + 3];
		int prefix = 8388608 + size;
		write_prefix(ret, prefix); 
		if(m_value)
			ret[3] = 0x01;
		else
			ret[3] = 0x00;
		return ret;
	}

	DataObject* from_bytes(byte* bytes, ByteOrder bo)
	{
		DataObject* ret;
		if(bytes[3] == 0x01)
			ret = new Bool(true);
		else
			ret = new Bool(false);
		return ret;
	}
};

#endif
