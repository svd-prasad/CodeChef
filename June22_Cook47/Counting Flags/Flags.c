#include <stdio.h>
main()
{
	int n, cases;
	unsigned long long int count;
	scanf("%d",&cases);
	while(cases > 0)
	{
		scanf("%d",&n);
		count = 0;
		count +=(unsigned long long int)2*n*(n-1)*(n-1);
		count += (unsigned long long int)n*(n-1)*(n-2);
		count += (unsigned long long int)2*n*(n-1)*(n-2)*(n-2);
		printf("%llu",count);
		--cases;
		if(cases > 0)
			printf("\n");
	}
} 