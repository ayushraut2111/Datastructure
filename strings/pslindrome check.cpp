#include<bits/stdc++.h>
using namespace std;
int palindrome(string s)
{
   for(int i=0;i<=s.length()/2;i++)
   {
       int j=s.length()-i-1;
       if(s[i]!=s[j])
       return 0;
   }
   return 1;
}
int palindrome1(string s)
{
    string h=s;
    reverse(s.begin(),s.end());
    if(h==s)
    return 1;
    return 0;
}
 int main()
 {
     string s;
     cin>>s;
     int x=palindrome1(s);
     if(x==1)
     cout<<"yes";
     else
     cout<<"no";
 }