    #include<iostream>
    #include<cstdio>
    using namespace std;
     
    int main()
    {	
    int t,n;
    long long int f;
    cin>>t;
    long int i;
    for(i=0;i<t;i++)
    {
    f=0;
    cin>>n;
    f=(long long int)(n)*(n-1)*(2 + 5*(n-2) + 2*(n-2)*(n-3) );
    cout<<f<<endl;
    }
     
     
    return 0;
    } 