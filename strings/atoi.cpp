#include<bits/stdc++.h>
using namespace std;
int atoi(string s)
{
    int sum=0,count=1;
    if(s[0]=='-')
    {
    for(int i=1;i<s.length();i++)
    {
        if(s[i]<48||s[i]>57)
        return -1;
    }
    reverse(s.begin()+1,s.end());
    for(int i=1;i<s.length();i++)
    {
        sum+=(s[i]-48)*count;
        count*=10;
    }
    return -1*sum;

    }
    else
    {
    for(int i=0;i<s.length();i++)
    {
        if(s[i]<48||s[i]>57)
        return -1;
    }

    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        sum+=(s[i]-48)*count;
        count*=10;
    }
    return sum;
    }

}
int main()
{
    string s;
    cin>>s;
    int x=atoi(s);
    cout<<x;
}