#include<bits/stdc++.h>
using namespace std;
int lsearch(int a[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        return i+1;
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
  int x=lsearch(a,n,k);
  if(x!=-1)
  cout<<"found at index "<<x<<endl;
  else
  cout<<"not found"<<endl;
}