#include<bits/stdc++.h>
using namespace std;
int fact(int n)
 {
     if(n==1)
     return 1;
     return n*fact(n-1);

 }
vector<string> aper(string s)
{
    int x=fact(s.length());
    vector<string>v;
    for(int i=0;i<x;i++)
    {
        swap(s[i%s.length()],s[(i+1)%s.length()]);
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    return v;
}
 int main()
 {
     string s;
     cin>>s;
     vector<string>v=aper(s);
     for(int i=0;i<v.size();i++)
     cout<<v[i]<<endl;
 }