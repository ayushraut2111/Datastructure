#include<bits/stdc++.h>
using namespace std;
vector<int> kfreq(vector<int>v,int k)
{
    unordered_map<int,int>m;
    for(int i=0;i<v.size();i++)
    {
        if(m.find(v[i])==m.end())
        {
            m.insert({v[i],1});
        }
        else
        m[v[i]]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int count=0;
   for(auto it=m.begin();it!=m.end()&&count<k;it++)
    {
        pq.push({it->second,it->first});
        count++;
    }
     for(auto it=m.begin();it!=m.end();it++)
     {
        if(it->second>pq.top().first)
        {
            pq.pop();
            pq.push({it->second,it->first});
        }
     }
     vector<int>d;
     while(!pq.empty())
     {
         d.push_back(pq.top().second);
         pq.pop();
     }
     return d;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int h;
        cin>>h;
        v.push_back(h);
    }
    int k;
    cin>>k;
    v=kfreq(v,k);
    for(auto x: v)
    {
        cout<<x<<endl;
    }
}