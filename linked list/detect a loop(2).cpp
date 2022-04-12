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
bool detectaloop(node* head)     // its time complexity is O(n^2)
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        node* ptr=head;
        while(ptr->next!=temp&& ptr!=temp&&ptr->next!=NULL)  // for every node run a loop until current node and check if current node next is equal to any node 
        {
            if(temp->next==ptr)
            {
                return true;
                }

            ptr=ptr->next;
        }
        temp=temp->next;
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