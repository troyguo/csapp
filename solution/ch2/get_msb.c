#include <stdio.h>
#include <assert.h>

/*
 * This file intended to get the msb of an int type
 */

int get_msb(int x)
{
		/*shift by w-8*/
		int shif_val =  (sizeof(int) -1) << 3;

		/*Arithmetic shift*/
		int xright = x >> shif_val;

		/*zero all but LSB*/
		return xright & 0xff;
}

int main(int argc, char *argv[])
{
		int msb = get_msb(0x12345678);

		assert(msb == 0x12);

		return 0;
}
