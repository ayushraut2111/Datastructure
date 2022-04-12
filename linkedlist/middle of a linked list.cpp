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
int middlelist(node* head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    return head->data;
    else
    {node*slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
    }
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,10);
    head=insertatlast(head,20);
    head=insertatlast(head,30);
    head=insertatlast(head,40);
    head=insertatlast(head,50);
    cout<<middlelist(head)<<endl;
    printnode(head);
   
}