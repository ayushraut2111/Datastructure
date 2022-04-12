#include<bits/stdc++.h>
using namespace std;
string removedup(string s)
{
    char ch;
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(st.empty()||s[i]!=st.top())
        st.push(s[i]);
        else
        {
            st.pop();
        }
    } 
    string s1;
    while(!st.empty())
    {
        s1+=st.top();
        st.pop();
    }
    reverse(s1.begin(),s1.end());
    return s1;
}
int main()
{
    string s;
    cin>>s;
    s=removedup(s);
    cout<<s<<endl;
    }