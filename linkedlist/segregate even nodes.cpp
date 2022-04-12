#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* insertatlast(node* head,int data)
{
    node *ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        return head;
    }
}
void printnode(node*head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
node* segregate(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    node* ptr=head;
    while(ptr!=temp->next)
    {
        if((ptr->data)%2!=0)
        {
            node* self=new node();
            self->data=ptr->data;
            ptr->data=ptr->next->data;
            ptr->next=ptr->next->next;
            node*newnode=temp;
            while(newnode->next!=NULL)
            newnode=newnode->next;
            newnode->next=self;
           
        }
        else
        ptr=ptr->next;
    }
    return head;
}
node*segregatelink(node* head)
{
    node* es=NULL,*ee=NULL,*os=NULL,*oe=NULL;
    node*temp=head;
    while(temp!=NULL)
    {
        if((temp->data)%2!=0)
        {
            if(os==NULL)
            {
                os=temp;
                oe=temp;
            }
            else
            {
                oe->next=temp;
                oe=temp;
            }
        }
        else
        {
            if(es==NULL)
            {
                es=temp;
                ee=temp;
            }
            else
            {
                ee->next=temp;
                ee=temp;
            }
        }
        temp=temp->next;
    }
    if(os==NULL||es==NULL)   //if there is no even or no odd number then return the same list
    return head;
    ee->next=os;
    oe->next=NULL;
    return es;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,17);
    head=insertatlast(head,15);
    head=insertatlast(head,8);
    head=insertatlast(head,12);
    head=insertatlast(head,10);
    head=insertatlast(head,5);
    head=insertatlast(head,4);
    head=segregatelink(head);
    printnode(head);
}


