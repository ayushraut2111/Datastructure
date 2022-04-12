#include<bits/stdc++.h>
using namespace std;
struct val
{
    int first;
    int second;
};
bool cmp(val a,val b)
{
    return a.first<b.first;
}
int maxchain(val p[],int n)
{
    sort(p,p+n,cmp);
    int dis[n];
    dis[0]=1;
    for(int i=1;i<n;i++)
    {
        dis[i]=1;
        int j=i-1;
        while(j>=0)
        {
            if(p[i].first>p[j].second)
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
    val p[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i].first=x;
        p[i].second=y;
    }
    cout<<maxchain(p,n);
}