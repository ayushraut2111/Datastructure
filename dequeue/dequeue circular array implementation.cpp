#include<bits/stdc++.h>
using namespace std;
struct dequeue
{
    int *arr;
    int size,cap,front;
    dequeue(int x)
    {
        cap=x;
        arr=new int[cap];
        size=0;
        front=0;
    }
    void frontinsert(int x)
    {
        if(size==cap)
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            front=(front-1+cap)%cap;
            arr[front]=x;
            size++;
        }
    }
    void deletefront()
    {
        if(size==0)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            front=(front+1)%cap;
            size--;
        }
    }
    void rearinsert(int x)
    {
         if(size==cap)
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            int temp=(front+size)%cap;
            arr[temp]=x;
            size++;
        }
    }
    void deleterear()
    {
        if(size==0)
        {
            cout<<"underflow"<<endl;
        }
        else
        {   
            size--;
        }
    }
    int getfront()
    {
        if(size==0)
        return NULL;
        else
        return arr[front];
    }
    int getrear()
    {
        if(size==0)
        return NULL;
        else
        return arr[(front+size-1)%cap];
    }
};
int main()
{
    
}