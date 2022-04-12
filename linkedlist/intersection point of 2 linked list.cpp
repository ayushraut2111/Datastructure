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
int intersect1(node* h1,node* h2)
{
    unordered_set<node*>s;
    node* temp=h1;
    while(temp!=NULL)
    {
        s.insert(temp);
        temp=temp->next;
    }
    temp=h2;
    while(temp!=NULL)
    {
        if(s.find(temp)!=s.end())
        return temp->data;
        temp=temp->next;
    }
    return 0;
}
int intersect2(node* h1,node* h2)
{
    node*temp=h1;
    int c1=0,c2=0,c3;
    while(temp!=NULL)
    {
        c1++;
        temp=temp->next;
    }
    temp=h2;
     while(temp!=NULL)
    {
        c2++;
        temp=temp->next;
    }
    c3=abs(c1-c2);
    if(c1>c2)
    {
        while(c3--)
        {
            h1=h1->next;
        }
    }
    else
    {
        while(c3--)
        {
            h2=h2->next;
        }
    }
    while(h1!=NULL&&h2!=NULL)
    {
        if(h1==h2)
        return h1->data;
        h1=h1->next;
        h2=h2->next;
    }
    return 0;
}
int main()
{
    node*h1=NULL;
    node* h2=NULL;
    h1=insertatlast(h1,5);
    h1=insertatlast(h1,8);
    h1=insertatlast(h1,7);
    h1=insertatlast(h1,10);
    h1=insertatlast(h1,12);
    h1=insertatlast(h1,15);
    h2=insertatlast(h2,9);
    h2->next=h1->next->next->next;
    cout<<intersect2(h1,h2);
}