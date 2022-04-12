#include<bits/stdc++.h>
using namespace std;
int binarysearch(int a[],int beg,int end,int k)     // to apply binary search the array should be sorted
{
    if(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==k)
        return mid+1;
        else if(a[mid]<k)
        return binarysearch(a,mid+1,end,k);
        else
        return binarysearch(a,beg,mid-1,k);
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    int k;
    cin>>k;
    int x=binarysearch(a,0,n-1,k);
    if(x!=-1)
  cout<<"found at index "<<x<<endl;
  else
  cout<<"not found"<<endl;
}