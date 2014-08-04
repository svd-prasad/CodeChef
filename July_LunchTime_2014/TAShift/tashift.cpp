#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
void computeLPSArray(char *pat, long int M, long int lps[])
{
    long long int len = 1;  // length of the previous longest prefix suffix
    long long int i = 1;
	lps[0] = 0;
	while(i <= M)
    {
      if(pat[i] == pat[len])
       {
         len++;
		 lps[i] = len;
		 i++;
       }
	   else if(len > 0)
	   {
			len = lps[len -1];
	   }
       else
	   {
		lps[i] = 0;
		i++;
	   } 
    }
}
int main()
{
	char *str1, *str2, *str;
	long int n, i,*lps, max = 0 , index;
	cin>>n;
	str1 = (char *)malloc(n * sizeof(char));
	str2 = (char *)malloc(n * sizeof(char));
	str = (char *)malloc((2* n)+1 * sizeof(char));
	lps = (long int *)malloc(2*(n) * sizeof(long int));
	cin>>str1>>str2;
	strcpy(str, "@");
	strcat(str, str1);
	strcat(str, str2);
	cout<<str<<endl;
	computeLPSArray(str, 2*n+1, lps);
	for(i = 0;i <= 2*n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	for(i = 1;i <= 2*n;i++)
	{
	
		if(max < lps[i])
		{
			max = lps[i];
			index = i;
		}
	}
	cout<<"index"<<max<<endl;
	if(max)
		cout<<(index%n)-max; // index-max+1
	else
		cout<<"0";
	return 0;
}