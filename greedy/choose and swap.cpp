#include<bits/stdc++.h>
using namespace std;
string cands(string s)
{
    bool visited[256];
    for(int i=0;i<256;i++)
    {
        visited[i]=false;
    }
    string x=s;
    char min;
    char max;
    int i;
    visited[s[0]]=true;
    for(i=1;i<s.length();i++)
    {
        visited[s[i]]=true;
       int j=i-1;
       if(s[i]<s[j])
       {
           min=s[i];
           break;
       }
    }
    if(i==s.length())
    return s;
    for(int k=s[i]+1;k<256;k++)
    {
        if(visited[k]==true)
        {
            max=k;
            break;
        }
    }
    for(int p=0;p<s.length();p++)
    {
         if(s[p]==min)
        s[p]=max;
        else if(s[p]==max)
        s[p]=min;
    }
     if(x<s)
    return x;
    return s;
}
int main()
{
    string s;
    cin>>s;
    cout<<cands(s);
}
