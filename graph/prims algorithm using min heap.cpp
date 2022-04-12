#include<bits/stdc++.h>
using namespace std;
void prims(vector<int>v[],int n,bool visited[],int &ans, priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,int i)
{
    for(int j=0;j<n;j++)                  // push all the weights of that vertex if it is not added in mst
    {
        if(v[i][j]!=0&&visited[j]==false)    
       {
        pq.push({v[i][j],j});
        
       }
           
    }
    while(visited[pq.top().second]==true)   // if that vertex is already added in mst then pop the other weight of that vertex
    {
        pq.pop();
    }
    pair<int,int> x=pq.top();
    pq.pop();
    visited[x.second]=true;
    cout<<x.first<<endl;
    ans+=x.first;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)    
        {
            count++;
            break;
        }
    }
    if(count!=0)
    prims(v,n,visited,ans,pq,x.second);  // call prims algorithm for the min vertex 
}
int main()
{
   int n;
   cin>>n;
   vector<int>v[n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           int x;
           cin>>x;
           v[i].push_back(x);
       }
   } 
   bool visited[n];
   for(int i=0;i<n;i++)
   {
       visited[i]=false;
   }

   visited[0]=true;
   int ans=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   prims(v,n,visited,ans,pq,0);
   cout<<ans<<endl;
}