#include<bits/stdc++.h>
using namespace std;
struct myqueue
{
    int *arr;
    int cap;
    int size;
    myqueue(int n)
    {
        cap=n;
        size=0;
        arr=new int[cap];
    }
    void push(int x)
    {
        if(size==cap)
        cout<<"overflow"<<endl;
        else
        {
            arr[size]=x;
            size++;
        }
    }
    void pop()
    {
        if(size==0)
        {
            cout<<"underflow";
        }
        else
        {
            for(int i=0;i<size-1;i++)
            {
                arr[i]=arr[i+1];
            }
            size--;
        }
        
    }
    int getfront()
    {
        if(size==0)
        return INT_MAX;
        return arr[0];
    }
    int getrear()
    {
        if(size==0)
        {
            return INT_MAX;
        }
        return arr[size-1];
    }
        bool isempty()
        {
            return (size==0);
        }
        bool isfull()
        {
            return (size==cap);
        }
    
    int qsize()
    {
        return size;
    }

};
int main()
{
    myqueue q(4);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();
    q.pop();
    cout<<q.getfront();
    cout<<q.getrear();

}
