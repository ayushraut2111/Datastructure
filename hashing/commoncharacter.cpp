#include<bits/stdc++.h>
using namespace std;
string cchar(string s1, string s2)
{
    string s3;
    set<char>m1,m2,m3;
    for(int i=0;i<s1.length();i++)
    {
        m1.insert(s1[i]);
    }
    for(int i=0;i<s2.length();i++)
    {
        m2.insert(s2[i]);
    }
    for(int i=0;i<s1.length();i++)
    {
        if(m2.find(s1[i])==m2.end())
        m3.insert(s1[i]);
    }
    for(int i=0;i<s2.length();i++)
    {
        if(m1.find(s2[i])==m1.end())
        m3.insert(s2[i]);
    }
    if(m3.size()==0)
    return "-1";
    for(auto it=m3.begin();it!=m3.end();it++)
     s3.push_back(*it);
return s3;

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
     string s3=cchar(s1,s2);
     cout<<s3;
}