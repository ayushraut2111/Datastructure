#include<bits/stdc++.h>
using namespace std;
int rtoi(string s)
{
    map<char,int>m;
    m.insert({'I',1});
    m.insert({'V',5});
    m.insert({'X',10});
    m.insert({'L',50});
    m.insert({'C',100});
    m.insert({'D',500});
    m.insert({'M',1000});
    int res=0;
    for(int i=0;i<s.length();i++)
    {
        if(m[s[i]]<m[s[i+1]])
        {
            res+=m[s[i+1]]-m[s[i]];
            i++;       //incrementing i to next so that it come to i+1 character and after the loop ends i increment again and i goes to i+2 character 
        }
        else
        res+=m[s[i]];
    }
    return res;
}
 int main()
 {
     string s;
     cin>>s;
     int x=rtoi(s);
     cout<<x;
 }