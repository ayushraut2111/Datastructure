#include<bits/stdc++.h>
using namespace std;
string lcp(string s[],int n)
{
    string temp=s[0];
    int i;
    for(i=0;i<s[0].length();i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s[j].find(s[0][i])!=i)
            {
                if(i==0)
                return "-1";
                return temp.substr(0,i);
            }
            else{
                s[j][i]='0';
            }
        }
    }
    if(i==temp.length())
    return temp;
    return "-1";
}
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    string x=lcp(s,n);
    cout<<x;
}