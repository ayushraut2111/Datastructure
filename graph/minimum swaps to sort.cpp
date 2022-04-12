#include<bits/stdc++.h>
using namespace std;
int findswap(vector<int>v)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    bool visited[v.size()];
    for(int i=0;i<v.size();i++)
    {
        pq.push(v[i]);
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(visited[v[i]]==false)
        {
            if(v[i]!=pq.top())
            {
                visited[v[i]]=true;
                visited[pq.top()]=true;
                count++;
                pq.pop();
            }
            else
            {
                visited[v[i]]=true;
                pq.pop();
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        v.push_back(k);
    }
    cout<<findswap(v);
}