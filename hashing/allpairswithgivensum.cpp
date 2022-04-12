#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> allPairs(int a[],int b[],int n,int m,int x)
{
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++)
    {
        if(s.find(x-b[i])!=s.end())
        {
            v.push_back(make_pair(x-b[i],b[i]));
        }
    }
    sort(v.begin(),v.end());
    return v;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    cin>>b[i];
    int x;
    cin>>x;
    vector<pair<int,int>>v=allPairs(a,b,n,m,x);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
