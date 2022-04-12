#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
node* insertatbegin(node* head,int data)
{
    node*ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        ptr->next=head;
        head=ptr;
        return head;
    }
}
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
node* randominsert(node*head,int data,int loc)
{
    node*ptr=new node();
    ptr->data=data;
    if(loc==1)
    {
        ptr->next=head;
        head=ptr;
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
        temp->next=ptr;
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
        node*temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    
}
node* deletelast(node*head)
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
        node* temp=head,*temp1;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        delete(temp);
        return head;
    }
}
node* randomdelete(node* head,int loc)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(loc==1)
    {
        head=head->next;
        return head;
    }
    else
    {
        node*temp,*temp1;
        temp=head;
        for(int i=0;i<loc-1;i++)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        delete(temp);
        return head;
    }
}
void searchlist(node*head,int data)
{
    int i=0,flag=0;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    else  if(head->data==data)
    {
        cout<<"item found at location "<<i+1<<endl;
        flag=1;
    }
    else
    {
        node*temp=head;
        while(temp->next!=NULL)
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
    }
    if(flag==0)
    cout<<"item not found"<<endl;
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
    node*head=NULL;
    head=insertatbegin(head,1);
   head=insertatbegin(head,2);
    head=insertatbegin(head,3);
    searchlist(head,1);
    printnode(head);
}