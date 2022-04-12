#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
    node*prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
struct dequeue
{
    node* front,*rear;
    int s;
    dequeue()
    {
        front=NULL;
        rear=NULL;
        s=0;
    }
    void frontinsert(int x)
    {
        node* ptr=new node(x);
        if(front==NULL)
        {
            front=ptr;
            rear=ptr;
        }
        else
        {
            ptr->next=front;
            front->prev=ptr;
            front=ptr;
        }
        s++;
    }
    void rearinsert(int x)
    {
        node* ptr=new node(x);
        if(front==NULL)
        {
            front=ptr;
            rear=ptr;
        }
        else
        {
            rear->next=ptr;
            ptr->prev=rear;
            rear=ptr;
        }
        s++;
    }
    int frontdelete()
    {
        if(front==NULL)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }
        int x=front->data;
        node* temp=front;
        front=front->next;
        front->prev=NULL;
        if(front==NULL)
        rear=NULL;
        delete(temp);
        s--;
        return x;

    }
    int reardelete()
    {
        if(rear==NULL)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }
        int x=rear->data;
        node* temp=rear;
        rear=rear->prev;
        rear->next=NULL;
        if(rear==NULL)
        front=NULL;
        delete(temp);
        s--;
        return x;
    }
    int getfront()
    {
        
        if(front==NULL)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }
        else
        return front->data;
    }
     int getrear()
    {
        
        if(rear==NULL)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }
        else
        return rear->data;
    }
    bool isempty()
    {
        return (front==NULL);
    }
    int size()
    {
        return s;
    }
};
int main()
{
    dequeue dq;
    dq.frontinsert(1);
    dq.frontinsert(2);
    dq.reardelete();
    cout<<dq.size()<<endl;
}