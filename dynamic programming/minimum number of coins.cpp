#include<bits/stdc++.h>
using namespace std;
vector<int> mincoin(int n)
{
    vector<int>v;
    int arr[10]={1,2,5,10,20,50,100,200,500,2000};
    while(n>=2000)
    {
        v.push_back(2000);
        n-=2000;
    }
    while(n!=0)
    {
        int x=*(upper_bound(arr,arr+10,n)-1);
        v.push_back(x);
        n-=x;
    }
    return v;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v=mincoin(n);
    for(auto x:v)
    {
        cout<<x<<endl;
    }
}