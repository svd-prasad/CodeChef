#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	unsigned long long int n, cases;
	unsigned long long int count;
	cin>>cases;
	while(cases > 0)
	{
		cin>>n;
		count = (unsigned long long int)(2*pow(n,4))-(7*pow(n,3))+(9*pow(n,2))-(4*n);
		printf("%llu",count);
		--cases;
		if(cases > 0)
			cout<<endl;
	}
	return 0;
} 