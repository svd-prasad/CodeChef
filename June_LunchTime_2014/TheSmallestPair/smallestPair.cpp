#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
void minimum(unsigned long int a[], unsigned long int n)
{
		unsigned long int minimum = ULONG_MAX, index, nextIndex;
		for(unsigned long int i = 0 ; i < n ; i++)
			if( minimum > a[i])
			{
				minimum = a[i];
				index = i;
			}
	    minimum = ULONG_MAX;
		for(unsigned long int i = 0 ; i < n; i++)
			if( minimum > a[i])
			{
				if(i != index)
				{
				minimum = a[i];
				nextIndex = i;
				}
			}
		cout<<a[index]+a[nextIndex]<<endl;
}
int main()
{
	unsigned long int *a, cases, n, i;
	cin >> cases;
	while(cases > 0)
	{
		cin >> n;
		a = (unsigned long int *)malloc(n * sizeof(unsigned long int));
		for(i = 0 ; i < n ; ++i)
			cin >> a[i];
		minimum(a, n);
		free(a);
		--cases;
	}
	return 0;
}