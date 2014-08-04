#include <stdio.h>
int main()
{
	long array[5] = {1,1,1,1,1};
	printf("%ld", array[array[array[array[array[array[1]]]]]]);
	return 0;
}
