#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
    node*prev;
};
node* insertatbegin(node*head,int data)
{
    node* ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        head->next=head;
        head->prev=head;
        return head;
    }
    else
    {
        node* temp=head;
        while(temp->next!=head)
        temp=temp->next;
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        temp->next=head;
        head->prev=temp;
        return head;
    }
}
node* insertatlast(node* head,int data)
{
    node*ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        head->next=head;
        head->prev=head;
        return head;
    }
    else{
    node*temp=head;
    while(temp->next!=head)
    temp=temp->next;
    temp->next=ptr;
    ptr->prev=temp;
    ptr->next=head;
    head->prev=ptr;
    return head;
}
}
node* randominsert(node* head,int data,int loc)
{
    node*ptr=new node();
    ptr->data=data;
    if(loc==1)
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        head->prev=temp;
        temp->next=head;
        return head;
    }
    else
    {
        node*temp=head;
        for(int i=0;i<loc-2;i++)
        {
            temp=temp->next;
        }
        ptr->next=temp->next;
        temp->next->prev=ptr;
        temp->next=ptr;
        ptr->prev=temp;
        return head;
    }
}
node* deletefrombegin(node* head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    else
    {
    node*temp;
    temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    head=head->next;
    temp->next=head;
    head->prev=temp;
    return head;
}
}
node* deletefromlast(node* head)
{
     if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    else
    {
    node*temp,*temp1;
    temp=head;
    while(temp->next!=head)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=head;
    head->prev=temp1;
    delete(temp);
    return head;
}
}
node* randomdelete(node*head,int loc)
{
    if(head==NULL)
    {
         cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(loc==1)
    {
        node* temp=head;
        while(temp->next!=head)
        temp=temp->next;
        head=head->next;
        temp->next=head;
        head->prev=temp;
        return head;
    }
    else
    {
        node* temp1;
        node* temp=head;
        for(int i=0;i<loc-1;i++)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next->prev=temp1;
        delete(temp);
        return head;
    }
}
void searchlist(node* head,int data)
{
    node*temp=head;
    int i=0,flag=0;
    if(head->data==data)
    {
         cout<<"item found at location "<<i+1<<endl;
    }
    else{
    while(temp->next!=head)
    {
        if(temp->data==data)
        {
            cout<<"item found at location "<<i+1<<endl;
            flag=1;
        }
        i++;
        temp=temp->next;
    }
    if(temp->data==data)
    {
        cout<<"item found at location "<<i+1<<endl;
            flag=1;
    }
    if(flag==0)
    cout<<"item not found"<<endl;
}
}
void clockprint(node* head)
{
    node*temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void anticlockprint(node* head)
{
    node* temp=head;
    while(temp->next!=head)
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->prev;
    }
    cout<<temp->data;
}
int main()
{
     node*head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    searchlist(head,4);
    clockprint(head);
}