#include<iostream>
using namespace std;
int stack[100],top=-1,n;
void push(int val)
{
    if(top==n-1)
        cout<<"overflow"<<endl;
    else
    {
        top=top+1;
        stack[top]=val;
    }

}
void pop()
{
    if(top==-1)
        cout<<"list is empty"<<endl;
    else

    {
        top-=1;
    }
}
void show()
{
    for(int i=top;i>=0;i--)
        cout<<stack[i]<<endl;
    if(top==-1)
        cout<<"stack is empty"<<endl;
}
int main()
{
    cout<<"enter total no. of elements in stack"<<endl;
    cin>>n;
    push(1);
    push(2);
    push(3);
    pop();
    show();
}
