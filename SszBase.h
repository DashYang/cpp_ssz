#ifndef __SSZ_BASE_H__
#define __SSZ_BASE_H__

/*
SPECs:
https://github.com/ethereum/research/tree/master/py_ssz
https://github.com/ethereum/eth2.0-specs/blob/master/specs/simple-serialize.md
*/

#define LENGTH_BYTES 	4
#define SSZ_CHUNK_SIZE 	128
typedef unsigned char byte;

enum ByteOrder {
	LITTLE,
//	BIG,
};

enum ObjectType {
	type_BOOL,
	type_UINT8,
	type_UINT16,
	type_UINT32,
	type_UINT64,
	type_BYTES,
	type_STRUCT,
	type_ARRAY,
};

class DataObject
{
public:
	DataObject(ObjectType t) {m_Type = t;}
	ObjectType m_Type;
	size_t len(DataObject *in);
};

class ssz
{
public:
	int newindex;

	virtual byte* to_bytes(size_t size, ByteOrder bo) = 0;
	virtual DataObject* from_bytes(byte* bytes, ByteOrder bo) = 0;
	void write_prefix(byte* dst, int prefix)
	{
		dst[0] = (prefix >> 16) & 0xff;
		dst[1] = (prefix >> 8)  & 0xff;
		dst[2] = (prefix >> 0)  & 0xff;
	}
};

size_t len(DataObject *in)
{
	return 0;
}

#endif
