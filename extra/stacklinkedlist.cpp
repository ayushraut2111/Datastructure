#include<iostream>
using namespace std;
int n,top=-1;
struct node
{
    int data;
    node *next;
};
node *head;
void push(int data)
{

    if(top==n-1)
        cout<<"overflow"<<endl;
    else
    {
        top=top+1;
        node *ptr=new node();
        if(ptr==NULL)
            cout<<"overflow"<<endl;
        else if(head==NULL)
        {
            ptr->data=data;
            ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->data=data;
            ptr->next=head;
            head=ptr;
        }
    }
}
void pop()
{
    if(top==-1)
        cout<<"underflow"<<endl;
    else
    {
        node*temp;
        temp=head;
        head=temp->next;
        delete(temp);
        top-=1;
    }
}
void print()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    if(top==-1)
        cout<<"stack is empty"<<endl;
}
int main()
{
    cout<<"enter total number of elements in stack"<<endl;
    cin>>n;
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    print();
}
