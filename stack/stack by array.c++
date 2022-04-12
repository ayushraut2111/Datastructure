#include<bits/stdc++.h>
using namespace std;
struct mystack
{
    int *arr;
    int cap;
    int top;
    mystack(int a)
    {
        cap=a;
        arr=new int[cap];
        top=-1;
    }
    void push(int data)
    {
        if(top==cap-1)
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=data;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            int res=arr[top];
            top--;
            return res;
        }
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"underflow"<<endl;
        }
        else
        return arr[top];
    }
    int size()
    {
        return top+1;
    }
    bool isempty()
    {
        return (top==-1);
    }


};
struct dynamicstack
{
    vector<int>v;
    int top=-1;
    void push(int data)
    {
        v.push_back(data);
    }
    int pop()
    {
        int res=v.back();
        v.pop_back();
        return res;
    }
    int peek()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool isempty()
    {
        return v.empty();
    }
};
int main()
{
    mystack s(5);
    s.push(1);
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.size();
}