#include<bits/stdc++.h>
using namespace std;
int nextgreater(int a[],int n)
{
    int b[n];
    stack<int>s;
    s.push(n-1);
    b[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty()&&a[i]>=a[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        b[i]=-1;
        else
        b[i]=a[s.top()];
        s.push(i);
    }
    for(int i=0;i<n;i++)
    cout<<b[i]<<endl;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    nextgreater(a,n);
}