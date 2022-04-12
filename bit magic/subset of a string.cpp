#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=pow(2,s.length());
    vector<char>v[n];
    for(int i=0;i<n;i++)
    {
        if(i==0)
        v[i].push_back(' ');
        else{
        int x=i;
        int count=0;
        while(x>0)
        {
            if(x&1==1)
            {
                v[i].push_back(s[count]);
            }
            x=x>>1;
            count++;
        }
        }
    }
    for(auto x:v)
    {
        for(int i=0;i<x.size();i++)
        {
            cout<<x[i];
        }
        cout<<endl;
    }
}