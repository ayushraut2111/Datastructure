#include<bits/stdc++.h>
using namespace std;
int isrotated(string s,string p)
{
    string s1=s+s;
    if(s1.find(p)!=-1)
    {
        if(s1.find(p)==2||s1.find(p)==s.size()-2)
        return 1;
    }
    return 0;
}
 int main()
 {
     string s,p;
      cin>>s>>p;
      int x=isrotated(s,p);
      cout<<x;
 }