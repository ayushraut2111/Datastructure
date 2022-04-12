#include<bits/stdc++.h>
using namespace std;
int postfix(char s[],int n)
{
    stack<int>p;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]!='+')&&(s[i]!='-')&&(s[i]!='*')&&(s[i]!='/'))
        {
            p.push(s[i]);
        }
        else
        {
            int x=p.top();
            p.pop();
            int y=p.top();
            p.pop();
            if(s[i]=='+')
            {
                x=x+y;
                p.push(x);
            }
            else if(s[i]=='-')
            {
                x=x-y;
                p.push(x);
            }
            else if(s[i]=='*')
            {
                x=x*y;
                p.push(x);
            }
            else 
            {
                x=x/y;
                p.push(x);
            }
        }
    }
    return p.top();
}
int main()
{
    int n;
    cin>>n;
     char s[n];
    for(int i=0;i<n;i++)
    cin>>s[i];
    int x=postfix(s,n);
    cout<<x;
}