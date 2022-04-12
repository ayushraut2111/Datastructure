#include<bits/stdc++.h>
using namespace std;
void sub(string s,string curr,int i,vector<string>&v)
{
    if(i==s.length())
    {
        v.push_back(curr);
        return ;
    }
    sub(s,curr,i+1,v);
    sub(s,curr+s[i],i+1,v);
}
int main()
{
  string s,curr;
  cin>>s;
  vector<string>v;
  sub(s,"",0,v);
  for(auto x:v)
  cout<<x<<endl;
}