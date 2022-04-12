#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
    v[j].push_back(i);
}
void shortestdistance(vector<int>v[],int size,int s)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    visited[i]=false;
    int dis[size];
    dis[s]=0;
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int r=q.front();
        q.pop();
        for(auto x: v[r])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                dis[x]=dis[r]+1;
                q.push(x);
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<dis[i]<<endl;
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
    shortestdistance(v,7,0);
}