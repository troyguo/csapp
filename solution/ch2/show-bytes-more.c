/*
 * show-bytes-more.c
 */

//2.57
#include <stdio.h>


typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for ( i = 0; i < len; i++ ) {
		printf(" %.2x", start[i]);
	}

	printf("\n");
}


void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}


void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}

//2.57 add more
void show_short(short x)
{
	show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
	show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(long x)
{
	show_bytes((byte_pointer)&x, sizeof(double));
}
//2.57 add more ends

void test_show_bytes (int val)
{
	int ival = val;

	float fval = (float) ival;
	int *pval = &ival;

	//2.57 adds
	short s_val = (short) val;
	long l_val = (long) val;
	double d_val = (double) val;

	show_int(ival);
	show_float(fval);
	show_pointer(pval);

	//2.57 adds
	show_short(s_val);
	show_long(l_val);
	show_double(d_val);

}

int main(int argc, char *argv[])
{

	int test_num = 328; //0x148

	test_show_bytes(test_num);

	return 0;
}
