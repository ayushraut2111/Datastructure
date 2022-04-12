#include<bits/stdc++.h>
using namespace std;
string reverse1(string s)
{
    int start=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            reverse(s.begin()+start,s.begin()+i);
            start=i+1;
        }
    }
    reverse(s.begin()+start,s.end());
    reverse(s.begin(),s.end());
    return s;
}
string reverse2(string s)
{
    string temp;
    vector<string>v;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]!='.')
         {
             temp+=s[i];
         }
         else
         {
             v.push_back(temp);
             v.push_back(".");
             temp.erase();
         }
        
     }
      v.push_back(temp);
      reverse(v.begin(),v.end());
      s.erase();
      for(int i=0;i<v.size();i++)
      {
          s+=v[i];
      }
      return s;
}
int main()
 {
     string s;
     getline(cin,s);
     string s1=reverse1(s);   
     cout<<s1<<endl;
 }