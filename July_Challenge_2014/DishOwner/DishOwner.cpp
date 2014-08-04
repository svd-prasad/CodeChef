#include <iostream>
#include <cstdlib>
using namespace std;
struct chef
{
	long int dish;
	struct chef *nextDish;
};
struct chef *appendList(struct chef *list1, struct chef *list2)
{	
	struct chef *head;
	head = list1;
	while(list1 -> nextDish)
		list1 = list1 -> nextDish;
	list1 -> nextDish = list2;
	return head;
}
int main()
{
	long int T, N ,Q, maxScore;
	long *S, dish1, dish2, dish, *dishToChef, i;
	struct chef *chefList, *temp;
	bool flag;
	cin >> T;
	while(T > 0)
	{
		cin >> N;
		S = (long *)malloc(N * sizeof(long));
		for(i = 0; i < N ; i++)
			cin >> S[i];
		chefList = (struct chef *)malloc(N * sizeof(struct chef));
		for(i = 0; i < N ; i++)
		{
			(chefList[i]) . dish = S[i];
			(chefList[i]) . nextDish = NULL;
		}
		maxScore = S[0];
		for(i = 1; i < N ; i++)
		{
			if(maxScore < S[i])
				maxScore = S[i];
		}
		dishToChef = (long *)calloc(maxScore, sizeof(long));
		for(i = 0; i < N ; i++)
			dishToChef[S[i]] = i + 1; //Chef starts from 1
		cin >> Q;
		while(Q > 0)
		{
			cin >> flag;
			if(!flag)
			{
				cin >> dish1 >> dish2;
				cout << dish1 <<" "<<dish2<<endl;
				if(dishToChef[dish1] == dishToChef[dish2])
				{
					cout<<"Invalid query!"<<endl;
				}
				else
				{
					/*if(S[dish1] > S[dish2])
					{cout<<"here";
						while(chefList[dishToChef[S[dish2]] - 1] . dish > 0)
						{
							dishToChef[chefList[dishToChef[S[dish2]] - 1] . dish] = dish1; 
						}
						chefList[dishToChef[S[dish1]] - 1] . nextDish = appendList(chefList[dishToChef[S[dish1]] - 1] . nextDish, chefList[dishToChef[S[dish2]] - 1]. nextDish);
					}*/
					if(S[dish1] < S[dish2])
					{cout<<"here";
						dishToChef[chefList[dishToChef[S[dish1]] - 1] . dish] = dish2;
						cout<<dishToChef[chefList[dishToChef[S[dish1]] - 1] . dish]<<endl;
						temp = chefList[dishToChef[S[dish1]] - 1] . nextDish;
						while(temp)
						{
							temp = temp -> nextDish;
							dishToChef[temp->dish] = dish2; 
							cout<<dishToChef[temp->dish]<<endl;
						}
						cout<<"here";
						chefList[dishToChef[S[dish2]] - 1] . nextDish = appendList(chefList[dishToChef[S[dish2]] - 1]. nextDish, chefList[dishToChef[S[dish1]] - 1]. nextDish);
					}
				}
			}
			else
			{
				cin >> dish;
				cout << dish<<endl;
				cout<< dishToChef[dish] + 1 <<endl;
			}
			--Q;
		}
		free(dishToChef);
		free(chefList);
		free(S);
		--T;
	}
	return 0;
}