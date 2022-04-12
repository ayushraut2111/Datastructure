#include<bits/stdc++.h>
using namespace std;
bool samefreq(string s)
{
    unordered_map<char,int>m;
    for(int i=0;i<s.length();i++)
    {
        if(m.find(s[i])==m.end())
        m.insert({s[i],1});
        else
        {
            m[s[i]]++;
        }
    }
    vector<int>v;
    for(auto it=m.begin();it!=m.end();it++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(),v.end());
     if(v[0]==1)
    {
        if(v[1]==v[v.size()-1])
        return 1;
    }
    if((v[0]==v[v.size()-1])||(v[0]==v[v.size()-1]-1))
    return 1;
    return 0;
}
 int main()
 {
     string s;
     cin>>s;
     int x=samefreq(s);
     cout<<x<<endl;
 }