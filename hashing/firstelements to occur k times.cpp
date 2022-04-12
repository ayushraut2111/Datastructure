#include<bits/stdc++.h>
using namespace std;
int firstElementKTime(int a[], int n, int k)
{
    unordered_map<int,int>m1;
    unordered_map<int,pair<int,int>>m2;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(m1.find(a[i])==m1.end())
        m1.insert({a[i],1});
        else
        m1[a[i]]++;
    }
    for(auto it=m1.begin();it!=m1.end();it++)
    {
        if(it->second>=k)
        s.insert(it->first);
    }
    if(s.empty())
    return -1;
    for(int i=0;i<n;i++)
    {
        if(m2.find(a[i])==m2.end())
        {
            m2.insert({a[i],{i,1}});
        }
        else
        {
            if(m2[a[i]].second<k)
            {
                m2[a[i]].first=i;
                m2[a[i]].second++;
            }
        }
    }
    int count=100000006;
    for(auto it=s.begin();it!=s.end();it++)
    {
        if(m2.find(*it)!=m2.end())
        {
            count=min(count,m2[*it].first);
        }
    }
    return a[count];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    int x=firstElementKTime(a,n,k);
    cout<<x;
}