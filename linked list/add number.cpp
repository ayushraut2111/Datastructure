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
node* insertnode(node* root,int data)
{
    node* temp=new node(data);
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    else
    {
        node* ptr=root;
        while(ptr->next!=NULL)
        ptr=ptr->next;
        ptr->next=temp;
        return root;
    }
}
void printnode(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
node* reverselist(node* head)
{
    node* prev,*curr,*next;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}
int sum(node*head)
{
    int sum1=0;
    int count=1;
    while(head!=NULL)
    {
        sum1+=(head->data)*count;
        count*=10;
        head=head->next;
    }
    return sum1;
}
node* addnode(node*l1,node*l2)
{
    int sum1=sum(l1);
    int sum2=sum(l2);
    int s=sum1+sum2;
    node* temp=NULL;
node* x=l1;
    while(s!=0)
    {
        int x=s%10;
        s/=10;

        temp=insertnode(temp,x);
    }
    return temp;
}

int main()
{
    unsigned int x;
    node* root=NULL;
    root=insertnode(root,2);
    root=insertnode(root,4);
    root=insertnode(root,3);
    node*root1=NULL;
    root1=insertnode(root1,5);
    root1=insertnode(root1,6);
    root1=insertnode(root1,4);
    node* temp=addnode(root,root1);
    printnode(temp);
}