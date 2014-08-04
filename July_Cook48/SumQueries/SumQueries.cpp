#include <iostream>
using namespace std;
int main()
{
	long long int N, Q;
	long int M;
	cin >> N >> M;
	while(M)
	{
		cin >> Q;
		if( Q < (N + 2) || Q > (3*N))
		{
			cout<<"0"<<endl;
		}
		else
		{
			if(Q >= (N+2) && Q <= N+2+((2*N - 1)/2))
					cout<< (Q - N - 1) <<endl;
			else if(Q <= (3*N) && Q >= N+2+((2*N - 1)/2)+1)
					cout<< ((3*N) + 1 - Q) <<endl;
		}
		--M;
	}
	return 0;
}