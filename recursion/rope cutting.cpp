#include<bits/stdc++.h>
using namespace std;
int maxrope(int n,int a,int b,int c)
{
    if(n==0)
    return 0;
    if(n<0)
    return -1;
    int x=max(maxrope(n-a,a,b,c),max(maxrope(n-b,a,b,c),maxrope(n-c,a,b,c)));
    if(x==-1)
    return -1;
    else return 1+x;
}
int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    if(maxrope(n,a,b,c)==-1)
    cout<<"not possible"<<endl;
    else
    cout<<maxrope(n,a,b,c);
}