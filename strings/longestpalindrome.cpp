#include<bits/stdc++.h>
 using namespace std;
 static bool cmp(pair<int,string>s1,pair<int,string>s2)
 {
     return s1.second.length()<s2.second.length();
 }
 static bool cmp1(pair<int,string>s1,pair<int,string>s2)
 {
     return s1.first<s2.first;
 }
 string palindrome(string s)
 {
     string s1=s;
     reverse(s1.begin(),s1.end());
     if(s1==s)
     return s;
     return "0";
 }
 string longestPalin (string s) {
        vector<pair<int,string>>v;
     for(int i=0;i<s.length();i++)
     {
         string temp;
         string s3;
         for(int j=1;j<=s.length()-i;j++)
         {
             s3=s.substr(i,j);
             temp=palindrome(s3);
             if(temp!="0")
               v.push_back(make_pair(i,temp));
         }
     }
     sort(v.begin(),v.end(),cmp);
     if(v[0].second.length()==v[v.size()-1].second.length())
     {
         sort(v.begin(),v.end(),cmp1);
         return v[0].second;
     }
     return v[v.size()-1].second;
    }
 /*string pcheck(string s)
 {
     vector<string>v;
     for(int i=0;i<s.length();i++)
     {
         string temp;
         string s3;
         for(int j=1;j<=s.length()-i;j++)
         {
             s3=s.substr(i,j);
             temp=palindrome(s3);
             if(temp!="0")
               v.push_back(temp);
         }
     }
     sort(v.begin(),v.end(),cmp);
     if(v[0].length()==v[v.size()-1].length())
     return v[0];
     else
     return v[v.size()-1];

 }*/
 int main()
 {
     string s;
     cin>>s;
     string x=longestPalin(s);
     cout<<x<<endl;
    

 }