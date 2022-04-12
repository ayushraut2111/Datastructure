#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
vector<int> candyprice(int candies[],int n,int k)
{
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    sort(candies,candies+n);
    int j=n-1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            ans+=candies[i];
            visited[i]=true;
            for(int l=j;l>j-k;l--)
            {
                visited[l]=true;
            }
            j=j-k;
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int>v;
    v.push_back(ans);
    sort(candies,candies+n,cmp);
    ans=0;
    j=n-1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            ans+=candies[i];
            visited[i]=true;
            for(int l=j;l>j-k;l--)
            {
                visited[l]=true;
            }
            j=j-k;
        }
    }
    v.push_back(ans);
    return v;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int candies[n];
    for(int i=0;i<n;i++)
    {
        cin>>candies[i];
    }
    vector<int>v=candyprice(candies,n,k);
    cout<<v[0]<<" "<<v[1];
}