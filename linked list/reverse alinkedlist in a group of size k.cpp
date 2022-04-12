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
node* reversealist(node* head,int k)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* prev=NULL,*curr=head,*next;
    int count=0;
    while(curr!=NULL&&count<k)    // first we will reverse a list in a size of k 
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    node* mainhead=reversealist(curr,k);   // then call the recursion for remaining node
    head->next=mainhead;     // joining the prev head to the returned new head of the remaining nodes because till this point our original head is still intact
    return prev;
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
    cout<<endl;
    head=reversealist(head,3);
    printclockwise(head);
}