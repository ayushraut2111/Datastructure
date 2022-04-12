#include<bits/stdc++.h>
using namespace std;
bool ratmaze(vector<int>adj[],int i,int j,int n, int m)
{
    if(i==n-1&&j==m-1)
    return true;
    bool x=false;
    bool y=false;
    if(i+1<n&&adj[i+1][j]!=0)
    {
        x=ratmaze(adj,i+1,j,n,m);
    }
    if(j+1<m&&adj[i][j+1]!=0)
    {
        y=ratmaze(adj,i,j+1,n,m);
    }
    if(x==true||y==true)
    return true;
    return false;
}
bool maze(vector<int>adj[],int n,int m)
{
    if(adj[0][0]==0)
    return false;
if(ratmaze(adj,0,0,n,m)==true)
return true;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            adj[i].push_back(x);
        }
    }
    if(maze(adj,n,m)==true)
    cout<<"yes";
    else
    cout<<"no";
}