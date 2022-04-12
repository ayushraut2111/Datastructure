#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int>v[],int i,int j)
{
    v[i].push_back(j);
}
bool DFSrec(vector<int>v[],int i,bool visited[],bool dcycle[])
{
    visited[i]=true;
    dcycle[i]=true;
    for(auto x: v[i])
    {
        if(visited[x]==false&&DFSrec(v,x,visited,dcycle)==true)   //if it is not visited yet and that vertex is a part of cycle then return true
        return true;
        else if(dcycle[x]==true)          // if it is a part of current cycle then return true
        return true;
    }
    dcycle[i]=false;
    return false;
}
bool DFSdis(vector<int>v[],int size)
{
    bool visited[size];
    bool dcycle[size];
    for(int i=0;i<size;i++)
    {
        visited[i]=false;
        dcycle[i]=false;
    }
    for(int i=0;i<size;i++)
    {
        if(visited[i]==false)
        {
            if(DFSrec(v,i,visited,dcycle)==true)
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int>v[7];
    addedge(v,0,1);
    addedge(v,2,3);
    DFSdis(v,7);
}