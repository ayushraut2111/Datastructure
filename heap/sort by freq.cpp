#include<bits/stdc++.h>
using namespace std;
vector<int> kfreq(vector<int>v)
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
    priority_queue<pair<int,int>>pq;
   for(auto it=m.begin();it!=m.end();it++)
    {
        pq.push({it->second,it->first});
    }
    vector<int>d;
    while(!pq.empty())
    {
        for(int i=0;i<pq.top().first;i++)
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
    v=kfreq(v);
    for(auto x: v)
    {
        cout<<x<<endl;
    }
}