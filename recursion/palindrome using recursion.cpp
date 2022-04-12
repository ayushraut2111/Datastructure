#include<bits/stdc++.h>
using namespace std;
int palindrome(string s,int l)
{
    if(s.length()/2==l)
    {
        if(s[s.length()-l-1]==s[l])
        return 1;
        else return 0;
    }
    if(palindrome(s,l+1))
    {
        if(s[s.length()-l-1]==s[l])
        return 1;
        else return 0;
    }
    else return 0;
}
bool palindrome1(string s,int start,int end)
{
    if(start>=end)
    {
        if(s[start]==s[end])
        return true;
        else return false;
    }
    if(s[start]==s[end]&&palindrome1(s,start+1,end-1)==true)
    return true;
    else return false;
}
int main()
{
    string s;
    cin>>s;
    if(palindrome1(s,0,s.length()-1))
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl; 
}