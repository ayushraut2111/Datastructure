#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int arr[4]={1,4,5,2};
    int *temp=arr;
    for(int i=0;i<4;i++)
    {
        temp[i]=1;
    }
    for(int i=0;i<4;i++)
    {
        cout<<arr[i];
    }
}
