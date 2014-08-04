#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	long long int *a, max = 0, temp;
	long int i, n, j;
	cin >> n;
	a = (long long int *)malloc(n * sizeof(long long int));
	for(i = 0; i < n; i++)
		cin >> a[i];
	for(i = 0 ; i< n-1;i++)
		for(j =i+1;j<n;j++)
		{
			temp = (a[i] & a[j]);
			if(max <  temp)
				max = temp;
		}
	cout<< max;
	return 0;
}