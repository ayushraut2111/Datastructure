#include<bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k) {
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k>=0)
            {arr[i]-=k;
        }
        else
        arr[i]+=k;
    }
    
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
    return arr[n-1]-arr[0];
    }
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    getMinDiff(arr,n,k);
}