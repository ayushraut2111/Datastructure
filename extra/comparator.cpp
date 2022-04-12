#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>v1,pair<int,int>v2)
{
    if(v1.first!=v2.first)
    return v1.first<v2.first;
    else
    return v1.second>v2.second;
   /* if(v1.first!=v2.first)
    {
        if(v1.first<v2.first)
        return true;
        return false;
    }
    else
    {if(v1.second>v2.second)
    return true;
    return false;
    }   */
    
}
int main()
{
    int n;
    cin>>n;
    vector< pair<int,int> >v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}