#include<bits/stdc++.h>
using namespace std;
int strstr(string s,string x)
{if(s.length()<x.length())
    return -1;
     int j;
    for(int i=0;i<=s.length()-x.length();i++)
    {
        for(j=0;j<x.length();j++)
        {
            if(x[j]!=s[i+j])
            break;
        }
        if(j==x.length())
        return i;

    }
    return -1;
}
int main()
{
    string s,x;
    cin>>s>>x;
    int p=strstr(s,x);
    cout<<p;
}