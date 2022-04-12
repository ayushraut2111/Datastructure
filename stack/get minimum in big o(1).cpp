#include<bits/stdc++.h>
using namespace std;
struct getminstack
{
    stack<int>m,a;
    void push(int x)
    {
        if(m.empty())
        {
            m.push(x);
            a.push(x);
        }
        m.push(x);
        if(x<a.top())
        a.push(x);
    }
    void pop()
    {
        if(m.top()==a.top())
        a.pop();
        m.top();
    }
    int getmin()
    {
        return a.top();
    }
};
int main()
{
    getminstack s;
    s.push(1);
    s.push(5);
    cout<<s.getmin();
}