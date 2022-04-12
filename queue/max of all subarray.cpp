#include<bits/stdc++.h>
using namespace std;
vector<int> maxarray(int arr[],int n,int k)
{
    queue<int>q;
    vector<int>v;
    int max;
    for(int i=n-1;i>n-k;i--)
    {
        if(q.empty())
        {
            q.push(arr[i]);
            max=arr[i];
        }
        else if(arr[i]>max)
        {
            q.push(arr[i]);
            max=arr[i];
        }
        else
        q.push(arr[i]);
    }
    v.push_back(max);
    for(int i=n-k;i>=0;i--)
    {
        int x=q.front();
        q.pop();
        if(x==max)
        max=-1;
        if(arr[i]>max)
        {
            q.push(arr[i]);
            max=arr[i];
        }
        else
        q.push(arr[i]);
        v.push_back(max);
    }
    return v;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int k;
    cin>>k;
    vector<int> v=maxarray(arr,n,k);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;
}