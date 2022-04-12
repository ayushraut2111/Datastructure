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
node* detectaloop(node* head,bool &detect)     
{
    if(head==NULL||head->next==NULL)
    {
        detect=false;
        return head;
    }
    node* fast=head,*slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)    // if fast and slow meet at any point then we say that there is a loop
        {
            break;
        }
    }
    if(fast!=slow)  // if fast and slow are not equal linked list ends at null then we return false
    {
        detect=false;
        return head;
    }
    detect=true;  
    slow=head;    // we move slow to the head pointer
    while(slow->next!=fast->next)   // we run loop until we got both's next equal 
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;  // after finding we change fast->next to null
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
    bool detect=false;
    head=detectaloop(head,detect);
    printclockwise(head);
    detect?cout<<"yes":cout<<"no";

}

// we run a two pointer fast and slow we increment fast by 2 if both fast and slow meet at any point then we say that there is a loop
// after we find a loop we move the slow pointer to the beginning of the list and then move slow and fast pointer one by one
// by moving them one by one they will meet at the beginning of the node where the loop starts to we do fast->next=null to break the loop