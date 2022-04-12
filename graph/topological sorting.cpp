#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
}
void DFS(vector<int>v[],int i,bool visited[],stack<int>&s)
{
    visited[i]=true;
    for(auto x: v[i])
    {
        if(visited[x]==false)
        DFS(v,x,visited,s);
    }
    s.push(i);
}
void tsorting(vector<int>v[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
    }
    stack<int>s;
    for(int i=0;i<size;i++)
    {
        if(visited[i]==false)
        DFS(v,i,visited,s);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
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
    tsorting(v,7);
}