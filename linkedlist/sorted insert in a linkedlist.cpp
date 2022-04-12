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
node* insertsort(node* head,int data)
{
    node* ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else if(head->data>data)
    {
        ptr->next=head;
        head=ptr;
        return head;
    }
    else
    {
        node* temp=head,*temp1;
        while(temp!=NULL)
        {
            if(temp->data<data)
            {
                temp1=temp;
                temp=temp->next;
            }
            else
            {ptr->next=temp1->next;
            temp1->next=ptr;
            return head;}
        }
        temp1->next=ptr;
        return head;
    }
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,10);
    head=insertatlast(head,20);
    head=insertatlast(head,30);
    head=insertatlast(head,40);
    head=insertsort(head,1);
    printnode(head);
}