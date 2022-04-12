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
node* mergelinklist(node* h1,node* h2)
{
    if(h1==NULL)
    return h2;
    if(h2==NULL)
    return h1;
    int c1=0,c2=0;
    node* temp=h1;
    while(temp!=NULL)
    {
        temp=temp->next;
        c1++;
    }
    temp=h2;
    while(temp!=NULL)
    {
        temp=temp->next;
        c2++;
    }
    if(c1>c2)
    {
        temp=h2;
        while(temp!=NULL)
        {
            node*temp1=h1;
            while(temp1!=NULL)
            {
                if((temp->data)<(h1->data))
                {
                    node* self=new node();
                    self->data=temp->data;
                    self->next=h1;
                    h1=self;
                    break;
                    
                }
                else if((temp->data)<(temp1->next->data))
                {
                     node* self=new node();
                    self->data=temp->data;
                    self->next=temp1->next;
                    temp1->next=self;
                    break;
                }
                else if(temp1->next==NULL)
                {
                     node* self=new node();
                    self->data=temp->data;
                    self->next=NULL;
                    temp1->next=self;
                    break;
                }
                else
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        return h1;
    }
    else
    {
         temp=h1;
        while(temp!=NULL)
        {
            node*temp1=h2;
            while(temp1!=NULL)
            {
                if((temp->data)<(h2->data))
                {
                    node* self=new node();
                    self->data=temp->data;
                    self->next=h2;
                    h2=self;
                    break;
                    
                }
                else if((temp->data)<(temp1->next->data))
                {
                     node* self=new node();
                    self->data=temp->data;
                    self->next=temp1->next;
                    temp1->next=self;
                    break;
                }
                else if(temp1->next==NULL)
                {
                     node* self=new node();
                    self->data=temp->data;
                    self->next=NULL;
                    temp1->next=self;
                    break;
                }
                else
                temp1=temp1->next;
            }
            temp=temp->next;
        }
        return h2;
    }
}
node* sortedmerge(node* h1,node* h2)
{
    if(h1==NULL)
    return h2;
    if(h2==NULL)
    return h1;
    node* head=NULL,*tail=NULL;
    if(h1->data<=(h2->data))
    {
        head=h1;tail=h1;
        h1=h1->next;
    }
    else
    {
        head=h1;tail=h2;
        h2=h2->next;
    }
    while(h1!=NULL&&h2!=NULL)
    {
        if(h1->data<=(h2->data))
        {
            tail->next=h1;
            tail=h1;
            h1=h1->next;
        }
        else
        {
            tail->next=h2;
            tail=h2;
            h2=h2->next;
        }
    }
    if(h1==NULL)
    tail->next=h2;
    else
    tail->next=h1;
    return head;
}
int main()
{
    node*h1=NULL,*h2=NULL;
    h2=insertatlast(h2,10);
    h2=insertatlast(h2,20);
    h2=insertatlast(h2,30);
    h1=insertatlast(h1,5);
   
    h1=sortedmerge(h1,h2);
    printnode(h1);
    
}