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
node* reverseinpair(node* head,int k)
{
    if(head==NULL)
    return NULL;
    node* curr=head,*prev=NULL,*next=NULL;
    while(curr!=NULL&&k>0)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        k--;
    }
        node* tail=reverseinpair(curr,2);
        head->next=tail;
        return prev;
    }
node* reverse(node* head)
{
    node* temp=head;
    while(temp!=NULL&&temp->next!=NULL)
    {
        swap(temp->data,temp->next->data);
        temp=temp->next->next;
    }
    return head;
}  
node* reversenode1(node* head)
{
    if(head==NULL||head->next==NULL)
    return NULL;
    node* prev=head,*next=head->next->next;
    node*curr=head->next;
    curr->next=prev;
    head=curr;
    curr=next;
    while(curr!=NULL&&curr->next!=NULL)
    {
        next=curr->next->next;
        node* hell=curr->next;
        hell->next=curr;
        prev->next=hell;
        prev=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}  
int main()
{
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,2);
    head=insertatlast(head,4);
    head=insertatlast(head,5);
    head=insertatlast(head,6);
    head=insertatlast(head,7);
    head=insertatlast(head,8);
    printnode(head);
    cout<<endl;
    head=reversenode1(head);
    printnode(head);
}