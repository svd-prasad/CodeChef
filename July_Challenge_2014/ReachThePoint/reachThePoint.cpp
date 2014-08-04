#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	long int i, j;
	unsigned int T;
	cin >> T;
	while(T > 0)
	{
		cin >> i >> j;
		cout << i << j << endl;
		--T;
	}
	return 0;
}