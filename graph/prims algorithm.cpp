#include<bits/stdc++.h>
using namespace std;
void prims(vector<int>v[],int n,bool visited[],int &ans)
{
    pair<int,int>p={INT_MAX,INT_MAX};     //make a pair to save the minimum weight and its vertex
    for(int i=0;i<n;i++)
    {
            int j=0;
        if(visited[i]==true)        // if the vertex is added to the mst then check for the minimum weight
        {
            for(auto x:v[i])
            {
                if(x<p.first&&x!=0&&visited[j]==false)  // if we find the min weight and that vertex is not added in the mst then save it 
                {
                    cout<<i<<" "<<j<<endl;
                    p.first=x;
                    p.second=j;
                }
                j++;
            }
        }
    }
    ans+=p.first;       // add the min weight to the ans
    visited[p.second]=true;  // add the vertex to the mst
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
    prims(v,n,visited,ans);    // if any of the vertex is not in mst the call prims algorithm again
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
   prims(v,n,visited,ans);
   cout<<ans<<endl;
}