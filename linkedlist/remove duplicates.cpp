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
node* removesame1(node* head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node*temp,*temp1;
    temp=head;
    temp1=head->next;
    while(temp1->next!=NULL)
    {
        if(temp->data==temp1->data)
        {
            temp->next=temp1->next;
            temp1=temp1->next;
        }
        else
        {
            temp=temp->next;
            temp1=temp1->next;
        }
    }
   if(temp->data==temp1->data)
    temp->next=NULL;
    return head;
}
node* removesame2(node* head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node* temp=head;
    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            temp->next=temp->next->next;

        }
        else
        temp=temp->next;
    }
    return head;
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
int main()
{
    node* head=NULL;
    head=insertatlast(head,20);
    head=insertatlast(head,20);
    head=insertatlast(head,20);
    head=insertatlast(head,20);
    head=insertatlast(head,10);
    printnode(head);
    cout<<endl;
    head=removesame2(head);
    printnode(head);
}
