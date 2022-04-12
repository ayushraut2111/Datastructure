#include<bits/stdc++.h>
using namespace std;
bool checkp(string s)
{
    stack<char>p;
    for(int i=0;i<s.length();i++)
    {
        if(p.empty())
        p.push(s[i]);
        else if(s[i]=='['||s[i]=='('||s[i]=='{')
        {
            p.push(s[i]);
        }
        else if(s[i]==']'&&p.top()!='[')
        {
            return false;
        }
         else if(s[i]==')'&&p.top()!='(')
        {
            return false;
        }
         else if(s[i]=='}'&&p.top()!='{')
        {
            return false;
        }
        else
        p.pop();
    }
    if(p.empty())
    return true;
    else
    return false;
}
int main()
{
    string s;
    cin>>s;
    int  x=checkp(s);
    if(x==1)
    cout<<"yes";
    else
    cout<<"no";

}