#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
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
int palindrome(node *head)
{
    if(head->next==NULL)
    return 1;
    node* temp=head;
    while(temp->next!=NULL&&temp!=NULL)
    {
        node*temp1=temp;
        node* temp2;
        while(temp1->next!=NULL)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if((temp1->data)!=(temp->data))
        return 0;
        temp2->next=NULL;
        temp=temp->next;
    }
    return 1;
}
int palindromelist(node* head)
{
    node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp=head;
    node* temp1;
    count=(count+1)/2;
    while(count--)
    {
        temp1=temp;
        temp=temp->next;
    }
    node* curr=temp;
    node*prev=NULL,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    temp1->next=prev;
    node* ptr=head,* self=prev;
    while(ptr!=temp1->next&&self!=NULL)
    {
        if((ptr->data)!=(self->data))
        {
            return 0;
        }
        ptr=ptr->next;
        self=self->next;
    }
    return 1;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,'r');
    head=insertatlast(head,'a');
    head=insertatlast(head,'d');
    head=insertatlast(head,'d');
    head=insertatlast(head,'a');
    head=insertatlast(head,'r');
    int x=palindromelist(head);
    if(x==0)
    cout<<"not a palindrome"<<endl;
    else
    cout<<"palindrome"<<endl;
}