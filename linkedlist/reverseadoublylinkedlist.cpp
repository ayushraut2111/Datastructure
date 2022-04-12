#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
    node*prev;
};

node* revedoubllist(node* head)
{
    node* curr=head;
    node*next=NULL,*prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* insertatlast(node* head,int data)
{
    node* ptr=new node();
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
        ptr->prev=temp;
        return head;
    }
}
void clockprint(node*head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
}
void anticlockprint(node* head)
{
    if(head==NULL)
    cout<<"list is empty"<<endl;
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->prev;
        }
    }
}
int main()
{
    node*head=NULL;
    head=insertatlast(head,1);
   head=insertatlast(head,2);
   head=insertatlast(head,3);
   clockprint(head);
   head=revedoubllist(head);
     anticlockprint(head);

}