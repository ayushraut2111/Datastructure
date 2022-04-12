#include<bits/stdc++.h>
using namespace std;
vector<int> ksort(vector<vector<int>>v)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto x:v)
    {
        for(auto y:x)
        {
            pq.push(y);
        }
    }
    vector<int>c;
    while(!pq.empty())
    {
        c.push_back(pq.top());
        pq.pop();
    }
    return c;
}
struct triplet
{
    int val,apos,vpos;
    triplet(int a,int b,int c)
    {
        val=a;
        apos=b;
        vpos=b;
    }
};
struct mycmp
{
bool operator()(triplet &t1,triplet &t2)
{
    return t1.val>t2.val;  
}
};
vector<int> ksort1(vector<vector<int>>v)
{
    priority_queue<triplet,vector<triplet>,mycmp>pq;
    for(int i=0;i<v.size();i++)
    {
        triplet t(v[i][0],i,0);
        pq.push(t);
    }
    vector<int>res;
    while(!pq.empty())
    {
        triplet curr=pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap=curr.apos;
        int vp=curr.vpos;
        if(vp+1<v[ap].size())
        {
            triplet t(v[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        vector<int>c;
        for(int j=0;j<x;j++)
        {
            int n;
            cin>>n;
            c.push_back(n);
        }
        v.push_back(c);
    }
    vector<int>c=ksort1(v);
    for(auto x:c)
    {
        cout<<x<<endl;
    }
}