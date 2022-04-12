#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
    int dis[n];                                 
    dis[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        dis[i]=arr[i];
        int j=i-1;
        while(j>=0){
        if(arr[j]<arr[i])             // to maintain the increasing subsequence
        {
            dis[i]=max(dis[i],dis[j]+arr[i]);
        }
        j--;
        }
    }
    return *max_element(dis,dis+n);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<lis(arr,n);
}