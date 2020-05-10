#include <stdio.h>
#include <assert.h>

/*all bits equal 1*/
int A(int x)
{
	return !~x;
}

/*all 0*/
int B(int x)
{
	return !x;
}


/*lsb: all 1*/
int C(int x)
{
		A(x | ~0xff);
}

/*msb: all 0*/
int D(int x)
{
		return B(x >> ((sizeof(int) -1 ) << 3) & 0xff);
}

int main(int argc, char * argv[])
{
		int all_bit_one = ~0;
		int all_bit_zero = 0;

		assert(A(all_bit_one));
		assert(!B(all_bit_one));
		assert(C(all_bit_one));
		assert(!D(all_bit_one));

		assert(!A(all_bit_zero));
		assert(B(all_bit_zero));
		assert(!C(all_bit_zero));
		assert(D(all_bit_zero));

		/*test magic numbers*/
		assert(!A(0x1234ff));
		assert(!B(0x1234ff));
		assert(C(0x1234ff));
		assert(D(0x1234ff));

		assert(!A(0x1234));
		assert(!B(0x1234));
		assert(!C(0x1234));
		assert(D(0x1234));

		return 0;
}
