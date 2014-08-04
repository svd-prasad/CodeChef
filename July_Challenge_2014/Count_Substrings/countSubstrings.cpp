//BUG --> Taking 100000 Input stirng using cin >> str; which extends to multiple lines
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	unsigned long long int cases, size, count, i;
	char *str;
	cin >> cases;
	while(cases > 0)
	{
		cin >> size;
		count = 0;
		str = (char *)malloc(size * sizeof(char));
		for(i = 0 ; i < size ; i++)
			cin >> str[i];  
		for(i = 0 ; i < size ; i++)
			if(str[i] - '0')
				++count;
		cout<<count*(count+1)/2<<endl;
		free(str);
		--cases;
	}
	return 0;
}