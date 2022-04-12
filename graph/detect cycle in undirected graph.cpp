#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
    v[j].push_back(i);
}
bool DFS(vector<int>v[],int source,bool visited[],int parent)
{
    visited[source]=true;
    for(auto x:v[source])
    {
        if(visited[x]==false)
        {
            if(DFS(v,x,visited,source)==true)
            return true;
        }
        else if(x!=parent)
        return true;
    }
    return false;
}
bool DFSdis(vector<int>v[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<size;i++)
    {
        if(visited[i]==false)
        {
            if(DFS(v,i,visited,-1)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int>v[7];
    addedge(v,1,2);
    addedge(v,2,3);
    addedge(v,3,1);
    cout<<DFSdis(v,7);
}