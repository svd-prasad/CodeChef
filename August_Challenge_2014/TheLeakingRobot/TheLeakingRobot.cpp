#include <iostream>
using namespace std;
bool isOdd(long long n)
{
  if (n & 1)
    return 1;
  else
    return 0;
}
int main()
{
	long long int T, x ,y;
	bool xFlag;
	cin >> T;
	while(T > 0)
	{
		cin >> x >> y;
		if(x <= 0 &&  !isOdd(x))
		{
			if(y >= x && y <= -x)
				cout<<"YES"<<endl;
			else
			{
				if(!isOdd(y)) 
				{
					if(y <= 0)
					{
						if(x >= y && x <= (1 - y)) 
							cout<<"YES"<<endl;
						else
							cout<<"NO"<<endl;
					}
					else
					{
						if(x >= -y && x <= (y - 1))
							cout<<"YES"<<endl;
						else
							cout<<"NO"<<endl;
					}
				}
				else
					cout<<"NO"<<endl;
			}
		}
		else if(x > 0 &&  isOdd(x))
		{
			if(y >= (1 - x) && y <= (x + 1))
				cout<<"YES"<<endl;
			else
			{
				if(!isOdd(y))
				{
					if(y <= 0)
					{
						if(x >= y && x <= (1 - y))
							cout<<"YES"<<endl;
						else
							cout<<"NO"<<endl;
					}
					else
					{
						if(x >= -y && x <= (y - 1))
							cout<<"YES"<<endl;
						else
							cout<<"NO"<<endl;
					}
				}
				else
					cout<<"NO"<<endl;
			}
		}
		else if(!isOdd(y))
		{
			if(y <= 0)
			{
				if(x >= y && x <= (1 - y))
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
			else
			{
				if(x >= -y && x <= (y - 1))
					cout<<"YES"<<endl;
				else
					cout<<"NO"<<endl;
			}
		}
		else
			cout<<"NO"<<endl;
		--T;
	}
	return 0;
}
