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
bool detectaloop(node* head)     // its time complexity is O(n) but this will require a change in the datastructure 
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    node* temp=head,*ptr;  // ptr=dummy node
    while(temp->next!=NULL)
    {
        if(temp->next==ptr)
        {
            return true;
        }
       node* temp1=temp;
       temp=temp->next;
       temp1->next=ptr;
    }
    return false;
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
    head=insertatlast(head,5);
    head=insertatlast(head,6);
    head=insertatlast(head,7);
    head=insertatlast(head,8);
    printclockwise(head);
    node* temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=head->next->next->next;
    cout<<endl;
    detectaloop(head)?cout<<"yes":cout<<"no";
}

// this will change the next pointer of every node to any dummy node and if we reach any node whose next is already 
// pointing to the dummy node then we say that this list contains a loop