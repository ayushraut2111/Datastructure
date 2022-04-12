#include<bits/stdc++.h>
using namespace std;
struct stack1
{
    queue<int>q1,q2;
    int s=0;
    void push(int x)
    {
        if(q1.empty())
        q1.push(x);
        else
        {
            while(!q1.empty())      //copying all the elements of this main queue into another dummy queue so that we can insert
            {                       // new item at the first place so when we call pop function it will return the newly added item
                q2.push(q1.front());  // because we inserted our new item at the first place
                q1.pop();
            }
            q1.push(x);
            while(!q2.empty())  // copying back all the items to the main queue
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        s++;
    }
    int  pop()
    {
        int x=q1.front();
        q1.pop();
        s--;
        return x;
    }
    int size()
    {
        return s;
    }
    bool isempty()
    {
        return q1.empty();
    }

};
int main()
{
    stack1 s;
    s.push(10);
    s.push(20);
    cout<<s.pop();
}