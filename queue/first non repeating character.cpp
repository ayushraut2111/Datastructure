#include<bits/stdc++.h>
using namespace std;
string nonrepeating(string s)
{
    string s1;
    s1+=s[0];
    for(int i=1;i<s.length();i++)
    {
        int c[26]={0};
        for(int j=0;j<=i;j++)
        {
            c[s[j]-97]++;
        }
        int count=0;
        for(int k=0;k<26;k++)
        {
            if(c[s[k]-97]==1)
            {
                s1+=s[k];
                count++;
                break;
            }
        }
        if(count==0)
        {
            s1+='#';
        }
    }
    return s1;
}
int main()
{
    string s;
    cin>>s;
    s=nonrepeating(s);
    cout<<s;
}