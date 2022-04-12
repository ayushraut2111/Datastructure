#include<bits/stdc++.h>
using namespace std;
void substring(string s,string curr, int i,vector<string>&v)
{
    if(i==s.length())
    {
        v.push_back(curr);
        return;
    }
    else
    {
        substring(s,curr,i+1,v);
        substring(s,curr+s[i],i+1,v);
    }
}
int main()
{
    string s;
    cin>>s;
    vector<string>v;
    substring(s," ",0,v);
    for(auto x:v)
    cout<<x<<endl;
}