#include<bits/stdc++.h>
using namespace std;
int lis(int arr[],int n)
{
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        if(v.empty()||arr[i]>v.back())
        v.push_back(arr[i]);
        else
        {
            swap(arr[i],*upper_bound(v.begin(),v.end(),arr[i]));
        }
    }
    return v.size();
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