#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)
    cin>>b[i];
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    s.insert(a[i]);
    int count=0;
    for(int i=0;i<m;i++)
    {
        if(s.find(b[i])==s.end())
        {
            count++;
            break;
        }
    }
    if(count==0)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
}