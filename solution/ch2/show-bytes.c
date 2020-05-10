/*
 * show-bytes.c
 */

#include <stdio.h>
#include <string.h>


typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	for (size_t i = 0; i < len; i++ ) {
		printf(" %.2x", start[i]);
	}

	printf("\n");
}


void show_int(int x)
{
	printf("int: ");
	show_bytes((byte_pointer)&x, sizeof(int));
}

void show_long(long x)
{
	printf("long: ");
	show_bytes((byte_pointer)&x, sizeof(long));
}

void show_float(float x)
{
	printf("float: ");
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	printf("pointer: ");
	show_bytes((byte_pointer)&x, sizeof(void *));
}

void test_show_bytes (int val)
{
	int ival = val;
	float fval = (float) ival;
	int *pval = &ival;
	const char *s = "abcdef";
	long lval = (long)val;

	show_int(ival);
	show_float(fval);
	show_long(lval);
	show_pointer(pval);

	printf("string: ");
	show_bytes((byte_pointer) s , strlen(s));
}

int main(int argc, char *argv[])
{

	int test_num = 328; //0x148

	test_show_bytes(test_num);

	return 0;
}
