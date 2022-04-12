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
        return head;
    }
}
node* removeduplicate(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        node* ptr=temp->next;
        if(temp->data==ptr->data)   // if both data are equal then delete equal data and check again without moving to next pointer
        {
            temp->next=ptr->next;
            delete(ptr);
        }
        else                //   if we dont get equal then move to the next element
        temp=temp->next;
    }
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
    head=insertatlast(head,1);
    head=insertatlast(head,1);
    head=insertatlast(head,1);
    head=insertatlast(head,2);
    head=insertatlast(head,2);
    head=insertatlast(head,2);
    head=insertatlast(head,3);
    head=insertatlast(head,3);
    head=insertatlast(head,4);
    head=insertatlast(head,4);
    head=insertatlast(head,4);
    printclockwise(head);
    cout<<endl;
    head=removeduplicate(head);
    printclockwise(head);
}