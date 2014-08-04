#include <iostream>
#include <cstdlib>
using namespace std;
int GCD(unsigned long int a, unsigned long int b)
{
	    unsigned long int r;
        while(b != 0)
        {
                r = a % b;
                a = b;
                b = r;
        }
        return a;
}
int main()
{
	unsigned long int i, n, *a, triples = 0, j, k;
	cin >> n;
	a = (unsigned long int *)malloc(n*sizeof(unsigned long int));
	for(i = 0; i < n; i++)
		cin >> a[i];
	for(i = 0 ; n > 2 && i <= n - 3 ; i++)
		for(j = 1 ; j <= n - 2 ; j++)
			for(k = 2 ; k <= n - 1 ; k++)		
			{	
				if(i < j && j < k && i < k)
				{
					if(GCD(GCD(a[i] , a[j]), a[k]) == 1)
					{
						++triples;
					}
						
				}
			}
	cout<<triples<<endl;
	free(a);
	return 0;
}