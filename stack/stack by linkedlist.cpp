#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
struct mystack
{
    node* head;
    int size;
    mystack()
    {
        head=NULL;
        size=0;
    }
    void push(int data)
    {
        node* ptr=new node();
        ptr->data=data;
        ptr->next=head;
        head=ptr;
        size++;
    }
    int pop()
    {
        if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return INT_MAX;    //any random large number
        }
        node* temp=head;
        int res=head->data;
        head=head->next;
        delete(temp);
        size--;
        return res;
    }
    int size()
    {
        return size;
    }
    bool isempty()
    {
        return(head==NULL);
    }
    int peek()
    {
        if(head==NULL)
        {
            cout<<"stack is empty"<<endl;
            return INT_MAX;
        }
        return head->data;
    }
};
int main()
{

}