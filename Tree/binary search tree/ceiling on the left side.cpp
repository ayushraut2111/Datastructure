#include<bits/stdc++.h>
using namespace std;
void ceiling(int arr[],int n)
{
    set<int>s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
        if(s.upper_bound(arr[i])!=s.end())
        {
            cout<<*(s.upper_bound(arr[i]))<<endl;
        }
        else
        cout<<-1<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    ceiling(arr,n);
}