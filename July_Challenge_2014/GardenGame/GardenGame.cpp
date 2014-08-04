#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;
unsigned long long int GCD(unsigned long long int a,unsigned long long int b)
{
		unsigned long long int r;
        while(b != 0)
        {
                r = a % b;
                a = b;
                b = r;
        }
        return a;
}
unsigned long  long int LCM(unsigned  long long int a,unsigned long long int b)
{
  unsigned long long  int gcd = GCD(a,b);
  return ((unsigned long long)(a*b))/(unsigned long long)gcd;
}
unsigned long long int calcLCMInArrayBasic(long int numArray[], long int len)
{
	unsigned long long int  i, lcmOfNumbers = 1;
	for (long int  c = 0; c < len; c++)
		lcmOfNumbers = LCM(lcmOfNumbers, numArray[c] );
	return lcmOfNumbers;
}
std::vector<long int> populateNumberOfWhistles(long int arr[],long int n, bool jumpsArray[])
{
	long long int jumps, var;
	long int j, i;
	bool FLAG;
	std::stack<long int> mystack;
	std::vector<long int> myvector;
	for(i = 1; i <= n; i++)
	{ 
	    jumps = 1;
		j = i;
		FLAG = 1;
		while(1)
		{ 
			j = arr[j];
			if(i != j)
			{
				if(!jumpsArray[j])
				{
					mystack.push(j);
					++jumps;
				}
				else
				{
					jumpsArray[i] = 1;
					break;
				}
			}
			else
			{
				jumpsArray[i] = 1;
				for (std::vector<long int>::iterator it = myvector.begin(); it < myvector.end(); it++)
					if((*it) == jumps)
					{
						FLAG = 0;
						break;
					}
				if(FLAG)
					myvector.push_back(jumps);
				while (!mystack.empty())
				{
					var = mystack.top();
					mystack.pop();
					jumpsArray[var] = 1;
				}
				break;
			}
		}
	}
	return myvector;
}
int main()
{
	long int *arr, i, n, size;
	bool *jumpsArray;
	int cases;
	std::vector<long int>cycleLengthVector;
	cin >> cases;
	while(cases)
	{
		cin >> n;
		arr = (long *)malloc((n+1) * sizeof(long)); 
		jumpsArray = (bool *)calloc((n+1) , sizeof(bool));
		for(i = 1; i <= n; i++) 
			cin >> arr[i];
		cycleLengthVector = populateNumberOfWhistles(arr, n,jumpsArray);
		size = 0;
		for (std::vector<long int>::iterator it = cycleLengthVector.begin(); it < cycleLengthVector.end(); it++)
			arr[size++] = *it;
		cout<<((unsigned long long int)calcLCMInArrayBasic(arr, size))% 1000000009<<endl;
		free(arr);
		free(jumpsArray);
		--cases;
	}
	return 0;
}