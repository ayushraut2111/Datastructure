#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int temp[n];
    temp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        temp[i]=max(temp[i-1]+arr[i],arr[i]);
    }
    cout<<*max_element(temp,temp+n);
}
