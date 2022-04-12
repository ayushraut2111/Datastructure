#include<bits/stdc++.h>
using namespace std;
int minjump(int arr[],int n)
{
    int j=0;
    int count=0;
    while(j<n)
    {
       
        j+=arr[j];
        cout<<j<<endl;
        count++;
    }
    return count-1;

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
    cout<<minjump(arr,n);
}