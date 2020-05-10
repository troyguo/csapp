#include <stdio.h>
#include <assert.h>

/*
 * Detect whether the machine is little endian or not.
 *
 * return: 1 -- little endian
 * 		   0 -- bit endian
 */

typedef unsigned char *byte_pointer;

int is_little_endian()
{

		int val = 0xff;
		byte_pointer pbyte = (byte_pointer)&val;

		if(*pbyte == 0xff) 
				return 1;
		else
				return 0;

}


int main(int argc, char *argv)
{
		if(is_little_endian()) {
				printf("Little endian\n");
		} else {
				printf("Big endian\n");
		}

		return 0;

}
