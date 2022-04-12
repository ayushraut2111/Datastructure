#include<iostream>
using namespace std;
int recursion(int arr[],int k,int count)
{ int x=0;
    if(count==k)
        return arr[k-1];
    else
        x=recursion(arr,k,count+1);
    return x;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"enter the nth number"<<endl;
    int k;
    cin>>k;
    cout<<recursion(arr,k,0);
}
