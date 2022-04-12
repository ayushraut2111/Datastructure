#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int beg,int end)
{
    int pivot=a[end];
    int i=beg-1;
    for(int j=beg;j<end;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[end]);
    return i+1;
}
void quicksort(int a[],int beg,int end)
{
    if(beg<end){
    int pi=partition(a,beg,end);
    quicksort(a,beg,pi-1);
    quicksort(a,pi+1,end);
    }

}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  quicksort(a,0,n-1);
  for(int i=0;i<n;i++)
  cout<<a[i]<<endl;
}