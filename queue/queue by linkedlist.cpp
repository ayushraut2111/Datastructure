#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
struct myqueue
{
    node* front,*rear;
    int size;
    myqueue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    void enqueue(int x)
    {
        node* ptr=new node(x);
        if(front==NULL)
        {
            front=ptr;
            rear=ptr;
            size++;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            size++;
        }
    }
    void dequeue()
    {
        if(front==NULL)
        cout<<"underflow"<<endl;
        else
        {
            node* temp=front;
            front=front->next;
            if(front==NULL)
            rear=NULL;
            delete(temp);
            size--;
        }
    }
    bool isempty()
    {
        return (front==NULL);
    }
    int qsize()
    {
        return size;
    }
    int getfront()
    {
        return front->data;
    }
    int getrear()
    {
        
        return rear->data;
    }
};
int main()
{
    myqueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.qsize()<<endl;
    q.dequeue();
    cout<<q.getrear()<<endl;

}