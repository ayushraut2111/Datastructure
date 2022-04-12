#include<bits/stdc++.h>
using namespace std;
const int CHAR=256;
int anagramcheck(string s,string p)
{
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());
    if(s==p)
    return 1;
    return 0;
}
int anagram1(string s,string p)
{
    int count[CHAR]={0};
    if(s.length()!=p.length())
    return 0;
    for(int i=0;i<s.length();i++)
    {
        count[s[i]]++;
        count[p[i]]--;
    }
    for(int i=0;i<CHAR;i++)
    {
        if(count[i]!=0)
        return 0;
    }
    return 1;
}
int main()
 {
     string s;
     cin>>s;
     string p;
     cin>>p;
     int x=anagram1(s,p);
     if(x==1)
     cout<<"yes";
     else
     cout<<"no";

     }