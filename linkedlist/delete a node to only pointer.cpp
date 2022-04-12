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
void deletenode(node* temp)
{
    temp->data=temp->next->data;
    temp->next=temp->next->next;
    cout<<temp->data<<endl;
    cout<<temp->next->data<<endl;
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
    head=insertatlast(head,80);
    printnode(head);
    cout<<endl;
    deletenode(head->next->next);

}