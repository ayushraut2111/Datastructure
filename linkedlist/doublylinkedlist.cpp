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
        head->prev=ptr;
        head=ptr;
        return head;
    }
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
node* randominsert(node*head,int data,int loc)
{
    node* ptr=new node();
    ptr->data=data;
    if(loc==1)
    {
        ptr->next=head;
        head->prev=ptr;
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
        temp->next->prev=ptr;
        temp->next=ptr;
        ptr->prev=temp;
        return head;
    }

}
node* deletefrombegin(node*head)
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
        head->prev=NULL;
        delete(temp);
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
        node* temp,*temp1;
        temp=head;
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
        head->prev=NULL;
        return head;
    }
    else
    {
        node*temp1,*temp;
        temp=head;
        for(int i=0;i<loc-1;i++)
        {
            temp1=head;
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next->prev=temp1;
        return head;
    }
}
void searchlist(node* head,int data)
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
                 if(flag==0)
                 cout<<"item not found"<<endl;
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
   searchlist(head,7);
    anticlockprint(head);
}