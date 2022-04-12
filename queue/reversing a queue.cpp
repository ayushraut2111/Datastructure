#include<bits/stdc++.h>
using namespace std;
queue<int> reverseq(queue<int>q)
{
    stack<int>s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}

queue<int> recursereversequeue(queue<int>q)
{
    if(q.empty())
    return q;
    int x=q.front();
    q.pop();
    q=recursereversequeue(q);
    q.push(x);
    return q;
}
int main()
{
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
     q.push(1);
    q.push(2);
    q.push(3);
     q=recursereversequeue(q);
    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
}