#include<iostream>
using namespace std;
void rotateleft(int arr[],int x,int n)
{
    if(x<1)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<endl;
        return ;
    }
    int temp=arr[0];
    int i;
    for(i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[i]=temp;
    rotateleft(arr,x-1,n);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;
    rotateleft(arr,x,n);

}
