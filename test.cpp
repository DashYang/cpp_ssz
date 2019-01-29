#include <stdio.h>
#include <iostream>
#include "SszBool.h"
using namespace std;

void pretty_printer(byte* source, int size)
{
	for(int i=0; i<size; i++)
	{
		printf("%02x ", source[i]);
	}
	printf("\n");
}

int main()
{
	Bool b_f(false);
	Bool b_t(true);
	byte* ret1 = b_f.to_bytes(b_f.len(),LITTLE); 
	byte* ret2 = b_t.to_bytes(b_f.len(),LITTLE); 
	pretty_printer(ret1, 4);
	pretty_printer(ret2, 4);

}
