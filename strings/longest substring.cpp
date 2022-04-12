#include<bits/stdc++.h>
 using namespace std;
 bool cmp(string s1,string s2)
 {
     return s1.length()<s2.length();
 }
 int longsubstring(string s)
 {
     int res=0;
     for(int i=0;i<s.length();i++)
     {
         int arr[256]={0};
         for(int j=i;j<s.length();j++)
         {
             if(arr[s[j]]==1)
             break;
             else
             {
                 arr[s[j]]=1;
                 res=max(res,j-i+1);
             }
         }
     }
     return res;
 }
 int lstring(string s)
 {
     vector<string>v;
     for(int i=0;i<s.length();i++)
     {
         string s1;
         for(int j=i;j<s.length();j++)
         {
             s1+=s[j];
             v.push_back(s1);
         }
     }
     for(int i=0;i<v.size();i++)
      {
          for(int j=0;j<v[i].length()-1;j++)
          {
              for(int k=j+1;k<v[i].length();k++)
              {
                  if(v[i][j]==v[i][k])
                  {
                      v[i]="0";
                      break;
                  }
              }
          }
      }
      sort(v.begin(),v.end(),cmp);
      return v[v.size()-1].length();
 }
 int main()
 {
   string s;
   cin>>s;
   int x=longsubstring(s);
   cout<<x<<endl;
 }
