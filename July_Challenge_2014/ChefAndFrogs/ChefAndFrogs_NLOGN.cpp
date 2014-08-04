#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct 
{
	unsigned long long int frogId;
	unsigned long long int coordinate;
	unsigned long long int reachableId;
}MyStruct;
MyStruct make_Pair(const unsigned long long int& num1, const unsigned long long int& num2, const unsigned long long int& num3)
{
    MyStruct pair;
    pair.frogId = num1;
    pair.coordinate = num2;
	pair.reachableId = num3;
    return pair;
}
struct myclass
{
  bool operator() (const MyStruct & s1, const MyStruct & s2)
  {
	return (s1.coordinate < s2.coordinate);
  }
}myobject;
struct myclass1
{
  bool operator() (const MyStruct & s1, const MyStruct & s2)
  {
	return (s1.frogId < s2.frogId);
  }
}myobject1;
int main()
{
	unsigned long long int N, P, k, coordinate, frogID, i, uniqueReachableId, size, frogI, frogJ;
	std::vector<MyStruct> vec;
	cin >> N >> k >> P;
	frogID = 1;
	while(N)
	{
		cin >> coordinate;
		vec.push_back(make_Pair(frogID, coordinate, 0));
		++frogID;
		--N;
	}
	std::sort(vec.begin(), vec.end(), myobject);
	uniqueReachableId = 1;
	vec[0].reachableId = uniqueReachableId;
	for (i = 0, size = vec.size() - 1; i < size; ++i)
	{
		if(vec[i+1].coordinate - vec[i].coordinate <= k)
			vec[i+1].reachableId = uniqueReachableId;
		else
		{
			++uniqueReachableId;
			vec[i+1].reachableId = uniqueReachableId;
		}
	}
	std::sort(vec.begin(), vec.end(), myobject1);
	while(P)
	{
		cin >> frogI >> frogJ;
		if(vec[frogI - 1].reachableId != vec[frogJ - 1].reachableId)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		--P;
	}
	/*for (i = 0, size = vec.size(); i < size; ++i)
	{
		cout<<"Frog ID: "<<vec[i].frogId<<"Coordinate: "<<vec[i].coordinate<<"ReachableId: "<<vec[i].reachableId<<endl;
	}*/
	return 0;
}