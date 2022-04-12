#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    else
    return p1.first<p2.first;
}
int bridge(vector<pair<int,int>>v,int n)
{
    int arr[n];
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        arr[i]=v[i].second;
    }
    int dis[n];
    dis[0]=1;
    for(int i=1;i<n;i++)
    {
        dis[i]=1;
        int j=i-1;
        while(j>=0){
        if(arr[j]<arr[i])
        {
            dis[i]=max(dis[i],dis[j]+1);
        }
        j--;
        }
    }
    return *max_element(dis,dis+n);
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
    cout<<bridge(v,n);
}