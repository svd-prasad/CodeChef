#include <iostream>
using namespace std;
bool isOdd( long long n)
{
  if (n & 1)
    return 1;
  else
    return 0;
}
int main()
{
	cout<< isOdd(1000000)<<endl;
	cout<< isOdd(-2) <<endl;
	cout<< isOdd(-3) <<endl;
	cout<< isOdd(-4) <<endl;
	cout<< isOdd(-109)<<endl;
return  0;
}
