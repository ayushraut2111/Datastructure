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
node* insertatlast1(node* head,int data)
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
        ptr->next=head->next;
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
int detectloop1(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    if(head->next==NULL)
    return 0;
    node*slow=head,*fast=head;
    while(slow!=NULL&&fast->next!=NULL&&fast!=NULL)
    {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return 1;
        
    }
    return 0;
}
int detectloop2(node* head)
{
    unordered_set<node*>s;
    node* temp=head;
    while(head!=NULL)
    {
        if(s.find(temp)!=s.end())
        return 1;
        s.insert(temp);
        temp=temp->next;
    }
    return 0;
}
int detectloop3(node* head)
{
    node* temp=new node();
    while(head->next!=NULL)
    {
        if(head==NULL)
        return 0;
        if(head==temp)
        return 1;
        node*ptr=head->next;
        head->next=temp;
        head=ptr;
    }
    return 0;
}
int main()
{
    node* head=NULL;
    head=insertatlast(head,10);
    head=insertatlast(head,20);
    head=insertatlast(head,30);
    head=insertatlast(head,40);
    head=insertatlast(head,50);
    head=insertatlast(head,60);
    head=insertatlast(head,70);
    head=insertatlast1(head,80);
    cout<<endl;
    int x=detectloop2(head);
    if(x==1)
    cout<<"yes"<<endl;
    else
    cout<<"No";
}