/*
 * 2.60
 *replace-byte.c
 */

#include <stdio.h>
#include <assert.h>

unsigned replace_byte (unsigned x, int i, unsigned char b)
{
		if(i < 0) {
				printf("error: i is negative\n");
				return x;
		}

		if(i > sizeof(unsigned) - 1) {
				printf("error: i too big\n");
				return x;
		}

		//i << 3; mean i*8
		unsigned mask = (unsigned)0xff << (i << 3);
		unsigned pos_byte = (unsigned)b << (i << 3);

		return (x & ~mask) | pos_byte;

}


int main(int argc, char * argv[])
{
		unsigned rep_2 = replace_byte(0x12345678, 2, 0xab);
		unsigned rep_0 = replace_byte(0x12345678, 0, 0xab);

		assert(rep_2 == 0x12ab5678);
		assert(rep_0 == 0x123456ab);

		return 0;
}
