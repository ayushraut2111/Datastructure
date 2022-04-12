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
node* reversealist(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* mainhead=reversealist(head->next);         // always return the reversed head
    node* temp=head->next;                          // assume that till recursive call every node is reversed so save current head->next
    temp->next=head;                               // reverse current head node also
    head->next=NULL;                              // and point current head->next to NULL
    return mainhead;                             // at last return the main reversed head 
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
    head=insertatlast(head,4);
    printclockwise(head);
    cout<<endl;
    head=reversealist(head);
    printclockwise(head);
}