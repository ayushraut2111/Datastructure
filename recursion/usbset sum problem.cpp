#include<bits/stdc++.h>
using namespace std;
void subsetsum(vector<int>v,int sum,int x,int &count,int i)
{
    if(sum==x)
    {
        count++;
        return;
    }
    if(i==v.size())
    return;
    subsetsum(v,sum,x,count,i+1);
    subsetsum(v,sum+v[i],x,count,i+1);
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int count=0;
    subsetsum(v,0,x,count,0);
    cout<<count<<endl;
}