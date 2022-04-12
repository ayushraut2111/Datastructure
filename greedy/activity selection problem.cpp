#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    return p2.second>p1.second;
}
int ASP(vector<pair<int,int>>v)
{
    int count=1;
    pair<int,int>p1=v[0];
    sort(v.begin(),v.end(),cmp);
    for(int i=1;i<v.size();i++)
    {
        if((p1.second>=v[i].first&&p1.second<=v[i].second)||(p1.first>=v[i].first&&p1.first<=v[i].second))
        continue;
        else
        {
            p1=v[i];
        count++;
        }
    }
    return count;
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
    cout<<ASP(v);
}