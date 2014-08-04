#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	long *array;
	array = (long *)malloc(5 * sizeof(long));
	for(int i = 0 ; i < 5 ; i++)
		array[i] = 1;
	cout<<array[array[array[array[array[array[1]]]]]];
	return 0;
}
