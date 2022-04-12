#include<bits/stdc++.h>
using namespace std;
void addedge(vector<pair<int,int>>v[],int i,int j,int x)
{
    v[i].push_back({j,x});
    v[j].push_back({i,x});
}
void dijkstra(vector<pair<int,int>>v[],bool visited[],int dist[],int source)
{
    // visited[source]=true;
    // for(auto x: v[source])
    // {
    //     if(visited[x.first]==false||dist[source]+x.second<dist[x.first])
    //     {
    //         dist[x.first]=min(dist[x.first],dist[source]+x.second);
    //         dijkstra(v,visited,dist,x.first);
    //     }
    // }
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        for(auto x:v[k])
        {
            if(visited[x.first]==false||dist[k]+x.second<dist[x.first])
            {
                dist[x.first]=min(dist[x.first],dist[k]+x.second);
                q.push(x.first);
                visited[x.first]=true;
            }
        }
    }

}
void graph(vector<pair<int,int>>v[],int n,int source)
{
    bool visited[n];
    int dist[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        dist[i]=INT_MAX;
    }
    dist[source]=0;
    dijkstra(v,visited,dist,source);
    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<endl;
    }
}
int main()
{
    vector<pair<int,int>>v[4];   // first=vertex <---=----> second=weight

    addedge(v,0,1,50);
    addedge(v,0,2,100);
    addedge(v,1,2,30);
    addedge(v,1,3,200);
    addedge(v,3,2,20);
    graph(v,4,0);
}