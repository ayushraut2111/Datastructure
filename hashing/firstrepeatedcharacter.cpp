#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     string s;
     cin>>s;
     int count=0;
     unordered_set<char>s1;
     for(int i=0;i<s.length();i++)
     {
         if(s1.find(s[i])!=s1.end())
         {
             cout<<s[i]<<endl;
             count++;
             break;
         }
         else
         s1.insert(s[i]);
     }
     if(count==0)
     {
         cout<<"not found"<<endl;
     }

 }