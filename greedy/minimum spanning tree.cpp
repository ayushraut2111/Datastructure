#include<bits/stdc++.h>
using namespace std;
void addedge(vector<vector<int>>adj[],int u,int v,int x)
{
    vector<int>temp={v,x};
    adj[u].push_back(temp);
    temp={u,x};
    adj[v].push_back(temp);
}
void mst(vector<vector<int>>adj[],int i,bool visited[],int& res)
{
    visited[i]=true;
    vector<int>v={INT_MAX,INT_MAX};
    for(auto x:adj[i])
    {
        if(visited[x[0]]==false)
        {
            if(x[1]<v[1])
            {
                v=x;
            }
        }
    }
    if(v[0]!=INT_MAX)
    {
        res+=v[1];
        mst(adj,v[0],visited,res);
    }
}
int sptree(int v,vector<vector<int>>adj[])
{
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    int res=0;
    mst(adj,0,visited,res);
    return res;
}
int main()
{
    vector<vector<int>>adj[3];
    addedge(adj,0,2,1);
    addedge(adj,0,1,5);
    addedge(adj,2,1,3);
    cout<<sptree(4,adj);
   /* for(int i=0;i<4;i++)
    {
        for(auto x: adj[i])
        {
            cout<<i<<" "<<x[0]<<" "<<x[1]<<endl;
        }
    }*/
}