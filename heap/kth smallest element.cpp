#include<bits/stdc++.h>
using namespace std;
int ksmall(vector<int>v,int k)
{
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(v[i]);
    }
    for(int i=k;i<v.size();i++)
    {
        if(v[i]<pq.top())
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    return pq.top();
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        v.push_back(d);
    }
    int k;
    cin>>k;
    cout<<ksmall(v,k);
}