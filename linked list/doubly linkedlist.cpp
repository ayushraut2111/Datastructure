#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
    node(int x)
    {
        data=x;
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
node* insertatlast(node* head,int x)
{
    node* ptr=new node(x);
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
        return head;
    }
}
node* insertatrandom(node* head,int x,int loc)
{
    node* ptr=new node(x);
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
        if(loc==1)
        {
            ptr->next=head;
            head->prev=ptr;
            head=ptr;
            return head;
        }
        else
        {
            node* temp=head;
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
}
node* deletefrombegin(node* head)
{
    if(head==NULL)
    {
        cout<<"underflow"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    {
        return NULL;
    }
    else
    {
        node* temp=head;
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
        cout<<"underflow"<<endl;
        return NULL;
    }
    else if(head->next==NULL)
    {
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
node* deleterandom(node* head,int loc)
{
    if(head==NULL)
    {
        cout<<"underflow"<<endl;
        return NULL;
    }
    else
    {
        if(loc==1)
        {
            node* temp=head;
            head=head->next;
            head->prev=NULL;
            delete(temp);
            return head;
        }
        else
        {
            node* temp=head,*temp1;
            for(int i=0;i<loc-1;i++)
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                temp1->next=NULL;
                delete(temp);
                return head;
            }
            temp1->next=temp->next;
            temp->next->prev=temp1;
            delete(temp);
            return head;
        }
    }
}
bool searchlist(node* head,int x)
{
    if(head==NULL)
    {
        cout<<"the list is empty"<<endl;
        return false;
    }
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            return true;

        }
        temp=temp->next;
    }
    return false;
}
void printclockwise(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
void printanticlockwise(node* head)
{
    node* temp=head;
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
int main()
{
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    head=insertatlast(head,4);
    // head=deleterandom(head,4);
    printclockwise(head);
    searchlist(head,0)?cout<<"yes found":cout<<"no";
}