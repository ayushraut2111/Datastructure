#include<bits/stdc++.h>
using namespace std;
int fib(int n,int memo[])
{
    if(memo[n]==-1)
    {
        int res;
        if(n==0||n==1)
        {
            res=n;
        }
        else
        res=fib(n-1,memo)+fib(n-2,memo);
        memo[n]=res;
    }
    return memo[n];
}
int main()
{
    int n;
    cin>>n;
    int memo[n+1];
    for(int i=0;i<n+1;i++)
    {
        memo[i]=-1;
    }
    fib(n,memo);
    for(int i=0;i<n+1;i++)
    {
        cout<<memo[i]<<endl;
    }

}