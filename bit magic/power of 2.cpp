#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    while(n>0)
    {
        if(n&1==1)
        count++;
        n=n>>1;
    }
    if(count==1)
    cout<<"yes this number is a power of 2"<<endl;
    else
    {
        cout<<"this number is not a power of 2"<<endl;
    }
}