#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
    v[j].push_back(i);
}
void DFS(vector<int>v[],int i,bool visited[])
{
    if(visited[i]==true)
    return ;
    cout<<i<<endl;
    visited[i]=true;
    for(auto x: v[i])
    {
        DFS(v,x,visited);
    }
}
void DFSdis(vector<int>v[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<size;i++)
    {
        if(visited[i]==false)
        DFS(v,i,visited);
    }
}
int main()
{
    vector<int>v[7];
    addedge(v,0,1);
    addedge(v,1,2);
    addedge(v,0,4);
    addedge(v,2,3);
    addedge(v,4,5);
    addedge(v,5,6);
    addedge(v,4,6);
    DFSdis(v,7);
}