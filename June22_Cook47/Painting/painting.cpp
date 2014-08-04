#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct 
{
	unsigned long long int tk;
	unsigned long long int ck;
}MyStruct;
MyStruct make_Pair(const unsigned long long int& num1, const unsigned long long int& num2)
{
    MyStruct pair;
    pair.tk = num1;
    pair.ck = num2;
    return pair;
}
struct myclass
{
  bool operator() (const MyStruct & s1, const MyStruct & s2)
  {
	return (s1.ck < s2.ck);
  }
}myobject;
int main()
{
	unsigned long long int n, m, tk, sum = 0, tk_count = 0;
	unsigned long long int h, ck, layers;
	std::vector<MyStruct> vec;
	cin >> n >> m >> h;
	layers = h;
	while(layers)
	{
		cin >> tk >> ck;
		sum += tk;
		vec.push_back(make_Pair(tk, ck));
		--layers;
	}
	if(sum < n * m)
	{
		cout<<"Impossible";
	}
	else
	{
		sum = 0;
		std::sort(vec.begin(), vec.end(), myobject);
		for (unsigned long long i = 0, size = vec.size(); i < size; ++i)
		{
			if(tk_count + vec[i].tk > n * m)
			{
				sum += vec[i].ck * ((n * m) - tk_count);
				break;
			}
			else
			{
				sum += vec[i].ck * vec[i].tk;
				tk_count += vec[i].tk;
			}
		}
		cout<<sum;
	}
	return 0;
}