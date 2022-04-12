#include<bits/stdc++.h>
using namespace std;
int largearea(int a[],int n)
{
    int ls[n];
    stack<int>s;
    s.push(0);
    ls[0]=-1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty()&&a[i]<=a[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        ls[i]=-1;
        else
        ls[i]=s.top();
        s.push(i);
    }

        int rs[n];
    stack<int>s1;
    s1.push(n-1);
    rs[n-1]=-1;
    for(int i=n-2;i>=0;i--)
    {
        while(!s1.empty()&&a[i]<=a[s1.top()])
        {
            s1.pop();
        }
        if(s1.empty())
        rs[i]=n;
        else
        rs[i]=s1.top();
        s1.push(i);
    }

       /*  for(int i=0;i<n;i++)
         {
             cout<<ls[i]<<" ";
         }
         cout<<endl;
         for(int i=0;i<n;i++)
         {
             cout<<rs[i]<<" ";
         } */
         int res=0;
         for(int i=0;i<n;i++)
         {
            int curr=a[i];
            curr+=(i-ls[i]-1)*a[i];
            curr+=(rs[i]-i-1)*a[i];
            res=max(res,curr);

         }
         return res;
}
    
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<largearea(a,n);
}