#include<bits/stdc++.h>
using namespace std;
void kclose(int arr[],int n,int x,int k)
{
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<k;i++)
    {
        pq.push({abs(arr[i]-x),i});
    }
    for(int i=k;i<n;i++)
    {
        if(abs((arr[i]-x))<=pq.top().first)
        {
            pq.pop();
            pq.push({abs(arr[i]-x),i});
        }
    }
    while(!pq.empty())
    {
        cout<<arr[pq.top().second]<<endl;
        pq.pop();
    }
}
int main()
{
    int n,sum;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x,k;
    cin>>x>>k;
    kclose(arr,n,x,k);
}