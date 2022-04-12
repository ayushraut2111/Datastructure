#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr.push_back(x);
        }
    int res=0;
    for(int i=1;i<n-1;i++)
    {
        int lmax=arr[i];
        for(int j=0;j<i;j++)
            lmax=max(lmax,arr[j]);
        int rmax=arr[i];
        for(int j=i+1;j<n;j++)
            rmax=max(rmax,arr[j]);
        res=res+min(rmax,lmax)-arr[i];
    }
    cout<<res<<endl;
}
