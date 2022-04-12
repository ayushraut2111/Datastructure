#include<bits/stdc++.h>
using namespace std;
int purmaxitem(int arr[],int n,int sum)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+n);
    int count=0,temp=0;
    while(!pq.empty())
    {
        temp+=pq.top();
        pq.pop();
        if(temp<=sum)
        {
            count++;
        }
        else
        break;
    }
    return count;
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
    cout<<purmaxitem(arr,n,sum);
}