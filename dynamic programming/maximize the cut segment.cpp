#include<bits/stdc++.h>
using namespace std;
int maxcut(int n,int x,int y,int z)
{
    if(n<0)
    return -1;
    if(n==0)
    return 0;
    int res=max(maxcut(n-x,x,y,z),max(maxcut(n-y,x,y,z),maxcut(n-z,x,y,z)));
    if(res==-1)
    return -1;
    return 1+res;
}
int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<maxcut(n,x,y,z);
}