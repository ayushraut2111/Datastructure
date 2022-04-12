#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
}
void kosaraju(vector<int>v[],int i,bool visited[])
{
    visited[i]=true;
    cout<<i<<" ";
    for(auto x:v[i])
    {
        if(visited[x]==false)
        {
            kosaraju(v,x,visited);
        }
    }

}
void DFSdis(vector<int>v[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
    }
    for(int i=size-1;i>=0;i--)
    {
        if(visited[i]==false)
        {
            kosaraju(v,i,visited);
            cout<<endl;
        }
    }

}
int main()
{
    vector<int>v[6];
    addedge(v,0,1);
    addedge(v,1,2);
    addedge(v,2,1);
    addedge(v,1,3);
    addedge(v,3,4);
    addedge(v,4,5);
    addedge(v,5,4);
    DFSdis(v,6);
}