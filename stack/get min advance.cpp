#include<bits/stdc++.h>
using namespace std;
struct minstack
{
    stack<int>s;
    int min;
    void push(int x)
    {
        if(s.empty())
        {
            s.push(x);
            min=x;
        }
        else if(x<=min)
        {
            s.push(x-min);
            min=x;
        }
        else
        s.push(x);
    }
    int pop()
    {
        int t=s.top();
        s.pop();
        if(t<=0)   //it is not the actual value the minimum value is the actual value
        {
            int res=min;
            min=min-t;
            return res;
        }
        else
        return t;

    }
    int getminimum()
    {
        return min;
    }
    int peek()
    {
        int t=s.top();
        return (t<=0)?min:t;   //if t is less than 0 then return minimum as actual value is the minimum value otherwise return t
    }
};
int main()
{
    minstack s;
    s.push(5);
    s.push(2);
    cout<<s.peek();
}