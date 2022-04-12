#include<bits/stdc++.h>
using namespace std;
vector<int> countelement(int a[],int n,int k)
{
    vector<int>v;
    unordered_map<int,int>m;
    for(int i=0;i<k;i++)
    {
        if(m.find(a[i])==m.end())
        m.insert({a[i],1});
        else
        m[a[i]]++;
    }
v.push_back(m.size());
for(int i=k;i<n;i++)
{
    m[a[i-k]]--;
    if(m[a[i-k]]==0)
    {m.erase(a[i-k]);}
    if(m.find(a[i])==m.end())
    m.insert({a[i],1});
    else
    m[a[i]]++;
v.push_back(m.size());
}
return v;
}
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
    vector<int>v=countelement(a,n,k);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";

}