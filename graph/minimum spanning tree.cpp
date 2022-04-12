#include<bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int>>v[],int i,int j,int x)
{
    v[i].push_back({j,x});
    v[j].push_back({i,x});
}
void spantree(vector<pair<int,int>>v[],int i,bool visited[],queue<int>&q)
{
    visited[i]=true;
    q.push(i);
    pair<int,int>min={INT_MAX,INT_MAX};
    for(auto x: v[i])
    {
        if(visited[x.first]==false)
        {
            if(x.second<min.second)
            {
                min=x;
            }
        }
    }
    
    if(min.first!=INT_MAX)
    {
    visited[min.first]=true;
    spantree(v,min.first,visited,q);
    }
    
}
void minst(vector<pair<int,int>>v[],int size)
{
    bool visited[size];
    for(int i=0;i<size;i++)
    visited[i]=false;
    queue<int>q,res;
    spantree(v,2,visited,q);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}
int main()
{
    vector<pair<int,int>>v[4];
    addedge(v,0,1,5);
    addedge(v,0,2,8);
    addedge(v,1,2,10);
    addedge(v,1,3,15);
    addedge(v,3,2,20);
    minst(v,4);
}