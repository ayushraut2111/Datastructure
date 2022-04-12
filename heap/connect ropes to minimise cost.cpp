#include<bits/stdc++.h>
using namespace std;
int connectropes(vector<int>v)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int res=0;
    for(auto x: v)
    {
        pq.push(x);
    }
    while(pq.size()>=2)
    {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        int temp=x+y;
        res+=temp;
        pq.push(temp);
    }
    return res;

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
    cout<<connectropes(v);
}