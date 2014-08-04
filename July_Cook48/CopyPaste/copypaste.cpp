#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	long int *a, count, n, i, *hash;
	int T;
	cin >> T;
	while(T > 0)
	{
		cin >> n;
		count = 0;
		a = (long int *)malloc(n * sizeof(long));
		hash = (long int *)calloc(100000 , sizeof(long));
		for(i = 0; i < n ; i++)
			cin >> a[i];
		for(i = 0; i < n ; i++)
		{
			if(!hash[a[i]])
			{
				hash[a[i]] = 1;
				++count;
			}
		}
		cout<<count<<endl;
		free(hash);
		free(a);
		--T;
	}
return 0;
}