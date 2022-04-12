#include<bits/stdc++.h>
using namespace std;
int leftmost(string s)
{
        int count[256]={0};
        for(int i=0;i<s.length();i++)
    {count[s[i]]++;
    }
    for(int i=0;i<s.length();i++)
    {
        if(count[s[i]]>1)
        return i;
    }
    
    return -1;
}
int main()
 {
     string s;
     cin>>s;
     int x=leftmost(s);
     cout<<x<<endl;
 }