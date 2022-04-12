#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
    v[j].push_back(i);
}
void BFS(vector<int>v[],int size,int s)       //when a source vertex is given then call this function
{ 
    bool visited[size];
    for(int i=0;i<size;i++)
    visited[i]=false;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int r=q.front();
        q.pop();
        cout<<r<<endl;
        for(auto x: v[r])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
void newBFS(vector<int>v[],int s,bool visited[])    // this function is with the BFSdis function
{
     queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int r=q.front();
        q.pop();
        cout<<r<<endl;
        for(auto x: v[r])
        {
            if(visited[x]==false)
            {
                q.push(x);
                visited[x]=true;
            }
        }
    }
}
void BFSdis(vector<int>v[],int size)    // if source vertex is not given or the graph is not connected to each other then call this function
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
            newBFS(v,i,visited);
        }
    }
}
int main()
{
    vector<int>v[5];
    addedge(v,0,1);
    addedge(v,1,2);
    addedge(v,0,4);
    addedge(v,4,3);
    BFSdis(v,5);
}