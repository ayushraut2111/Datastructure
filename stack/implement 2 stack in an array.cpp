#include<bits/stdc++.h>
using namespace std;
struct mystack
{
    int *arr;
    int cap;
    int top1;
    int top2;

mystack(int a)
{
    cap=a;
    top1=-1;
    top2=cap;
    arr=new int[cap];
}
void push1(int data)
{
    if(top1<top2-1)
    {
        top1++;
        arr[top1]=data;
    }
}
void push2(int data)
{
    if(top1<top2-1)
    {
        top2--;
        arr[top2]=data;
    }
}
int pop1()
{
    if(top1>=0)
    {
        int res=arr[top1];
        top1--;
        return res;
    }
    else
    exit;
}
int pop2()
{
    if(top2<=cap-1)
    {
        int res=arr[top2];
        top2++;
        return res;
    }
    else
    exit;
}
int size1()
{
    return top1;
}
int size2()
{
    return top2;
}
int peek1()
{
    return arr[top1];
}
int peek2()
{
    return arr[top2];
}
bool isempty1()
{
    return (top1==-1);
}
bool isempty2()
{
    return (top2==cap);
}
};
int main()
{

}