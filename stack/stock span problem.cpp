#include<bits/stdc++.h>
using namespace std;
int ssp(int a[],int n)
{
    int b[n];
    stack<int>s;
    s.push(0);
    b[0]=1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&a[i]>=a[s.top()])
        {
            s.pop();
        }
        if(!s.empty())
        b[i]=i-s.top();
        else
            b[i]=i+1;
        s.push(i);    

    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ssp(a,n);
}