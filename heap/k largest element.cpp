#include<bits/stdc++.h>
using namespace std;
void klarge(int arr[],int n,int k)
{
    priority_queue<int>pq(arr,arr+n);
    for(int i=0;i<k;i++)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
void klarge1(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);
    for(int i=k;i<n;i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    klarge1(arr,n,sum);
}