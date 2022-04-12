#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int k;
    cin>>k;
    unordered_map<int,int>m;
    for(int i=0;i<k;i++)
    {
        if(m.find(a[i])==m.end())
        m.insert({a[i],1});
        else
        m[a[i]]++;
    }
    cout<<m.size()<<endl;
    for(int i=k;i<n;i++)
    {
        m[a[i-k]]--;
        if(m[a[i-k]]==0)
        {m.erase(a[i-k]);}
        if(m.find(a[i])==m.end())
        m.insert({a[i],1});
        else
        m[a[i]]++;
        cout<<m.size()<<endl;
    }
}