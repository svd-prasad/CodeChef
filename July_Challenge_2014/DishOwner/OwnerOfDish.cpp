#include <iostream>
#include <cstdlib>
using namespace std;
struct dishList
{
	long int dish;
	struct dishList *next;
};
struct chef
{
	struct dishList *list;
};
struct dishList *appendNode(long int num)
{
	struct dishList *node;
	node = (struct dishList *)malloc(sizeof(struct dishList));
	if(!node)	
		cout<<"Memory Error";
	node -> dish = num;
	node ->next = NULL;
	return node;
}
int main()
{
	long int T, N ,Q, maxScore;
	long int *S, dish1, dish2, dish, *dishToChef, i;
	struct chef *chefs;
	struct dishList *temp, *list1, *list2;
	bool flag;
	cin >> T;
	while(T > 0)
	{
		cin >> N;
		S = (long *)malloc(N * sizeof(long));
		for(i = 0; i < N ; i++)
			cin >> S[i];
		chefs = (struct chef *)malloc(N * sizeof(struct chef));
		for(i = 0; i < N ; i++)
		{
			chefs[i] . list = appendNode(S[i]);
		}
		maxScore = S[0];
		for(i = 1; i < N ; i++)
		{
			if(maxScore < S[i])
				maxScore = S[i];
		}
		dishToChef = (long *)calloc(maxScore + 1, sizeof(long));
		for(i = 0; i < N ; i++)
			dishToChef[S[i]] = i + 1; //Chef starts from 1
		cin >> Q;
		while(Q > 0)
		{
			cin >> flag;
			if(!flag)
			{
				cin >> dish1 >> dish2;
				//cout << "Query "<<flag<<dish1 << " " <<dish2<<endl;
				if(dishToChef[dish1] == dishToChef[dish2])
				{
					cout<<"Invalid query!"<<endl;
				}
				else
				{
					if(dish1 < dish2)
					{
						temp = chefs[dishToChef[dish1] - 1] . list;
						while(temp)
						{
							dishToChef[temp->dish] = dish2; 
							temp = temp -> next;
						}
						list1 = chefs[dishToChef[dish2] - 1]. list;
						list2 = chefs[dishToChef[dish1] - 1]. list;
						while(list1 && list1 -> next)
							list1 = list1 -> next;
						if(list1)
							list1 -> next = list2;
						else
							list1 = list2;
						chefs[dishToChef[dish1] - 1]. list = NULL;
					}
					if(dish1 > dish2)
					{
						temp = chefs[dishToChef[dish2] - 1] . list;
						while(temp)
						{
							dishToChef[temp->dish] = dish1; 
							temp = temp -> next;
						}
						list1 = chefs[dishToChef[dish1] - 1]. list;
						list2 = chefs[dishToChef[dish2] - 1]. list;
						while(list1 && list1 -> next)
							list1 = list1 -> next;
						if(list1)
							list1 -> next = list2;
						else
							list1 = list2;
						chefs[dishToChef[dish2] - 1]. list = NULL;
					}
					//for(i = 0; i < N ; i++)
						//cout<<S[i]<<"dish Owned by"<<dishToChef[S[i]]<<endl; 
				}
			}
			else
			{
				cin >> dish;
				//cout << "Query "<<dish<<endl;
				cout<<dishToChef[dish]<<endl;
			}
			--Q;
		}
		free(dishToChef);
		free(chefs);
		free(S);
		--T;
	}
	return 0;
}