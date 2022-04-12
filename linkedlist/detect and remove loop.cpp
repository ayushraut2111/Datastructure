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
node* removeloop(node* head)
{
    if(detectloop2(head)==0)
    {
        return head;
    }
    else
    {
        vector<node*>v;
        node* temp=head;
        while(temp!=NULL)
        {
            if(find(v.begin(),v.end(),temp)==v.end())
            {v.push_back(temp);
            temp=temp->next;}
            else
            {
                v.push_back(NULL);
                break;
            }
        }
        for(int i=0;i<v.size();i++)
        {
           cout<< v[i]->data<<endl;
        }
        node* ptr;
        node*t=ptr;
        for(int i=0;i<v.size();i++)
        {
            t=v[i];
            t=t->next;
        }
        return ptr;
    }
    
}
void detectand(node* head)
{
    node* slow=head,*fast=head;
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow!=fast)
    return ;
    slow=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
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
    head=removeloop(head);
   printnode(head);
 
}