#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> kclose(vector<pair<int,int>>v,int k)
{
    priority_queue<pair<float,pair<int,int>>>pq;
    for(int i=0;i<k;i++)
    {
        float x=sqrt(pow(v[i].first,2)+pow(v[i].second,2));
        pq.push({x,{v[i].first,v[i].second}});
    }
    for(int i=k;i<v.size();i++)
    {
         float x=sqrt(pow(v[i].first,2)+pow(v[i].second,2));
         float y=pq.top().first;
         if(x<y)
         {
             pq.pop();
             pq.push({x,{v[i].first,v[i].second}});
         }
    }
    vector<pair<int,int>>d;
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
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int k;
    cin>>k;
    v=kclose(v,k);
    for(auto x: v)
    cout<<x.first<<" "<<x.second<<endl;
}