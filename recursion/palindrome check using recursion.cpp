#include<bits/stdc++.h>
using namespace std;
int palindrome(string s,int start,int end)
{
    if(start<=end){
    if(s[start]!=s[end])
    return -1;
    else
    {
        int x=palindrome(s,start+1,end-1);
        if(x==-1)
        return -1;
        else
        return 0;
    }
    }
}
int main()
{
    string s;
    cin>>s;                           
    if(palindrome(s,0,s.length()-1)==0)
    cout<<"yes this is a palindrome"<<endl;
    else
    cout<<"this is not a palindrome"<<endl;
}