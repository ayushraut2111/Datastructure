#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
    int dis[n];                                 
    dis[0]=1;
    for(int i=1;i<n;i++)
    {
        dis[i]=1;
        int j=i-1;
        while(j>=0){
        if(arr[j]<arr[i])
        {
            dis[i]=max(dis[i],dis[j]+1);
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
