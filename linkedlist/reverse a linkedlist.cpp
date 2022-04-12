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
node* reversealist(node* head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node* curr=head,*prev=NULL,*next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
node* recursionreverse1(node* head)
{
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    return head;
    node* uptail=recursionreverse1(head->next);
    node* curr=head->next;
    curr->next=head;
    head->next=NULL;
    return uptail;
}
node* recursionreverse2(node* head,node* prev)
{
    if(head==NULL)
    return prev;
    node*next=head->next;
    head->next=prev;
    node* uptail=recursionreverse2(next,head);
    return uptail;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,10);
    head=insertatlast(head,20);
    head=insertatlast(head,30);
    head=insertatlast(head,40);
    head=insertatlast(head,50);
    printnode(head);
    cout<<endl;
     head=recursionreverse2(head,NULL);
      printnode(head);

}