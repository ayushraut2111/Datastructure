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
node* insert(node* head,int x)
{
    node* ptr=new node(x);
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    node* temp=head,*temp1;
    while(temp!=NULL&&x>temp->data)
    {
        temp1=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        ptr->next=head;
        head=ptr;
        return head;
    }
    ptr->next=temp;
    temp1->next=ptr;
    return head;
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
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,6);
    head=insert(head,4);
    head=insert(head,0);
    head=insert(head,5);
    printclockwise(head);
}