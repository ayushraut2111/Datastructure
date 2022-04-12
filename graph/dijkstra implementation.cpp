#include<bits/stdc++.h>
#define vp vector<pair<int,int>> 
using namespace std;
void addedge(vp v[],int i,int j,int x)
{
    v[i].push_back({j,x});
    v[j].push_back({i,x});
}
void dijkstra(vp v[],int source,bool visited[],int dis[])
{
    visited[source]=true;
    pair<int,int>m={INT_MAX,INT_MAX};
    for(auto x:v[source])
    {
        if(visited[x.first]==false||dis[source]+x.second<dis[x.first])          // if it is not realaxed then update adjacent vertex distances and save min among all of them to call it for min path
        {
            dis[x.first]=min(dis[x.first],(dis[source]+x.second));
            dijkstra(v,x.first,visited,dis);
        }
    }
   
       
    
}
void graph(vp v[],int size,int source)
{
    bool visited[size];
    int dis[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
        dis[i]=INT_MAX;
    }
    dis[source]=0;
    dijkstra(v,source,visited,dis);
    for(int i=0;i<size;i++)         // printing distances 
    {
        cout<<dis[i]<<endl;
    }
}
int main()
{
    vector<pair<int,int>>v[4];
    addedge(v,0,3,8);
    addedge(v,1,2,7);
    addedge(v,1,3,10);
    graph(v,4,3);
}





// dijkstra by queue --------GFG------question
//full solution in GFG ques

/*void dijkstramain(vector<vector<int>> adj[],int s,vector<bool>&visited,vector<int>&dis)
    {
        visited[s]=true;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
        for(auto x: adj[k])
        {
            if(visited[x[0]]==false||(dis[x[0]]>(dis[k]+x[1])))
            {
                dis[x[0]]=min(dis[x[0]],(dis[k]+x[1]));
                visited[x[0]]=true;
                q.push(x[0]);
            }
        }
        }
       
           
        
    }
    */