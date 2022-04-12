#include<bits/stdc++.h>
using namespace std;
static bool cmp(pair<float,float>p1,pair<float,float>p2)
{
    return (p1.first/p1.second)>(p2.first/p2.second);
}
float knapsack(vector< pair<float,float> >v,int k)
{
    float ans=0;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        if(k>=v[i].second)
        {
            k-=v[i].second;
            ans+=v[i].first;
        }
        else
        {
            ans+=(v[i].first*k)/v[i].second;
            return ans;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector< pair<float,float> >v;
    for(int i=0;i<n;i++)
    {
        float a,b;
        cin>>a>>b;
        v.push_back({a,b});     //a=profit   b=weight
    }
    int k;
    cin>>k;
    cout<<knapsack(v,k)<<endl;
}