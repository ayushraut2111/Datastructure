#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
    node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
node* insertatbegin(node* head,int data)
{
    node* ptr=new node(data);
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
}
node* insertatlast(node* head,int data)
{
    node* ptr=new node(data);
    if(head==NULL)
    {
        head=ptr;
        head->next=head;
        head->prev=head;
    }
    else
    {
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
        ptr->prev=temp;
        head->prev=ptr;
        return head;
    }
}
node* insertrandom(node* head,int data,int loc)
{
    node* ptr=new node(data);
    if(loc==1)
    {
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        ptr->next=head;
        head->prev=ptr;
        head=ptr;
        temp->next=head;
        head->prev=temp;
        return head;
    }
    else
    {
        node* temp=head;
        for(int i=0;i<loc-2;i++)
        {
            temp=temp->next;
        }
        if(temp->next==head)
        {
            temp->next=ptr;
            ptr->prev=temp;
            ptr->next=head;
            head->prev=ptr;
            return head;
        }
        ptr->next=temp->next;
        temp->next->prev=ptr;
        temp->next=ptr;
        ptr->prev=temp;
        return head;
    }
}
node* deleteatbegin(node* head)
{
    if(head==NULL)
    {
        cout<<"underflow"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    {
        delete(head);
        return NULL;
    }
    else
    {
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=head->next;
        node* ptr=head;
        head=head->next;
        head->prev=temp;
        delete(ptr);
        return head;
    }
}
node* deletefromlast(node* head)
{
    if(head==NULL)
    {
        cout<<"underflow"<<endl;
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
node* deleterandom(node* head,int loc)
{
    if(loc==1)
    {
        node* temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        node* ptr=head;
        head=head->next;
        temp->next=head;
        head->prev=temp;
        delete(ptr);
        return head;
    }
    node* temp=head,*temp1;
    for(int i=0;i<loc-1;i++)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp->next==head)
    {
        temp1->next=head;
        head->prev=temp1;
        delete(temp);
        return head;
    }
    temp1->next=temp->next;
    temp->next->prev=temp1;
    delete(temp);
    return head;
}
bool searchlist(node* head,int x)
{
    if(head->data==x)
    {
        return true;
    }
    node* temp=head;
    while(temp->next!=head)
    {
        if(temp->data==x)
        return true;
        temp=temp->next;
    }
    if(temp->data==x)
    return true;
    return false;
}
void printclockwise(node* head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void printanticlockwise(node* head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    while(temp!=head)
    {
        cout<<temp->data<<endl;
        temp=temp->prev;
    }
    cout<<temp->data<<endl;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    head=insertatlast(head,4);  
    head=insertrandom(head,5,5);
    // head=deleterandom(head,4);
    printclockwise(head); 
    searchlist(head,7)?cout<<"found":cout<<"not found";
}