#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
node* insertatbegin(node* head,int data)
{
    node* ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        head->next=head;
        return head;
    }
    else
    {
         node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        head=ptr;
        temp->next=head;
        return head;
    }
}
node* insertatlast(node*head,int data)
{
    node*ptr=new node();
    ptr->data=data;
    if(head==NULL)
    {
        head=ptr;
        head->next=head;
        return head;
    }
    else
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
        return head;

    }
}
node* randominsert(node* head,int data,int loc)
{
    node* ptr=new node();
    ptr->data=data;
    if(loc==1)
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        head=ptr;
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
       temp->next=ptr;
       return head;
    }
}
node* delefrombegin(node* head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return NULL;
    }
    else if(head->next==head)
    {
        delete(head);
        return NULL;
    }
    else
    {
        node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
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
    else if(head->next==head)
    {
        delete(head);
        return NULL;
    }
    else
    {
       node*temp=head;
       node*temp1;
        while(temp->next!=head)
        {
            temp1=temp;
            temp=temp->next;
        } 
        temp1->next=head;
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
         node*temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        return head;
    }
    else
    {
        node*temp1,*temp;
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
void searchlist(node*head, int data)
{
    int i=0,flag=0;
     if(head==NULL)
     {
         cout<<"list is empty"<<endl;
     }
     else if(head->data==data)
     {
         cout<<"item found at location "<<i+1<<endl;
         flag=1;
     } 
     else
     {
         node*temp=head;
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
void printnode(node* head)
{
    node*temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int main()
{
     node*head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    searchlist(head,4);
   printnode(head);
}