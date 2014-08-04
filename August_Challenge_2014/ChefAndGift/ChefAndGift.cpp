#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int *a , n, k, i, T, even;
	cin >> T;
	while(T > 0)
	{
		cin >> n >> k;
		a = (int *)malloc(n * sizeof(int));
		for(i = 0; i < n ; i++)
			cin >> a[i];
		for(i = 0, even = 0 ; i < n ; i++)
		{
			if(!(a[i] % 2))
				++even;
			if(even == k )
				break;
		}
		if(i == n || !k)
			cout<<"NO"<<endl;
		else if(even == k)
			cout<<"YES"<<endl;
		free(a);
		--T;
	}
	return 0;
}