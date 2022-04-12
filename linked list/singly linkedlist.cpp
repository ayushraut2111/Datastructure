#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
node* insertatlast(node* head,int data)
{
    node* ptr=new node(data);
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
        return head;
    }
}
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
        head=ptr;
        return head;
    }
}
node* insertrandom(node* head,int data,int loc)
{
    node* ptr=new node(data);
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
            temp->next=ptr;
            return head;
        }
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
            delete(temp);
        }
        node* temp=head,*temp1;
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
bool searchlist(node* head,int x)
{
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
int main()
{
    node* head=NULL;
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    head=insertrandom(head,4,4);
    printclockwise(head);
    searchlist(head,7)?cout<<"yes":cout<<"no";

}