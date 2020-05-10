#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
		size_t x = 0x89abcdef;
		size_t y = 0x76543210;
		size_t res;

		res = (x & 0xff) | (y & ~0xff);
		assert(res == 0x765432ef);
		printf("res = 0x%0lx\n", res);

		return 0;
}
