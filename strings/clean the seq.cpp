#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        list<int>l;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            l.push_back(a[i]);
        }
        vector<int>v;
        list<int>l1(l.begin(),l.end());
        for(int i=1;i<=k;i++)
        {
            l.remove(i);
             list<int>::iterator tmp=l.begin();
             advance(tmp,1);
           
             int count=0;
            for(auto it=l.begin();it!=l.end();it++)
            {
               if(*it!=*tmp)
               {
                   count++;
               }
               tmp++;
            }
            v.push_back(count-1);
        }
        for(auto x: v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}