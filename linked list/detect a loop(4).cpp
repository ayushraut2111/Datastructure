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
bool detectaloop(node* head)     // its time complexity is O(n) by hashing
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
   unordered_set<node*>s;
   node* temp=head;
   while(temp->next!=NULL)
   {
       if(s.find(temp)!=s.end())
       {
           return true;
       }
       s.insert(temp);
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

// we insert every visited node into the hash table and check everytime before inserting that if it is already preset in hash table or not