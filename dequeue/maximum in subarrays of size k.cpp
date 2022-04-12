#include<bits/stdc++.h>
using namespace std;
vector<int> msub(int arr[],int n,int k)
{
    vector<int>v;
    deque<int>dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        dq.pop_back();
        dq.push_back(i);
    }
    v.push_back(arr[dq.front()]);
    for(int i=k;i<n;i++)
    {
        while(!dq.empty()&&dq.front()<=i-k)
        dq.pop_front();
        while(!dq.empty()&&arr[i]>=arr[dq.back()])
        dq.pop_back();
        dq.push_back(i);
        v.push_back(arr[dq.front()]);
    }
    return v;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int k;
    cin>>k;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<int>v=msub(arr,n,k);
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<endl;

}