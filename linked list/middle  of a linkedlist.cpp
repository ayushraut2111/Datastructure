#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
    node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
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
        ptr->prev=temp;
        return head;
    }
}
void middleofalist(node* head)
{
    if(head->next==NULL)
    {
        cout<<head->data<<endl;
        return ;
    }
    node* temp=head,*temp1=head;
    while(temp1!=NULL&&temp1->next!=NULL)
    {
        temp=temp->next;
        temp1=temp1->next->next;
    }
    cout<<temp->data<<endl;
    return ;

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
    // head=insertatlast(head,5);
    // head=insertatlast(head,6);
    printclockwise(head);
    cout<<endl;
    middleofalist(head);
}