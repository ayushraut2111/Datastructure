#include<iostream>
using namespace std;
int front=-1,rear=-1,maxi;
struct queue
{
    int data;
    queue * next;
};
queue *head;
void insert(int val)
{
    if(rear==maxi-1)
        cout<<"overflow"<<endl;
    else
    {
        if(front==-1&&rear==-1)
        {
            front=front+1;
            rear=rear+1;
        }
        else
        {
            rear=rear+1;
        }
            queue *temp=new queue();
            queue *ptr;
            temp->data=val;
            if(head==NULL)
            {
                head=temp;
            }
            else
            {
                ptr=head;
                while(ptr->next!=NULL)
                    ptr=ptr->next;
                ptr->next=temp;
                temp->next=NULL;
        }
    }
}
void deletei()
{
    if(front==-1||front>rear)
        cout<<"underflow"<<endl;
    else
    {
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
            queue *temp;
            temp=head;
            head=temp->next;
            delete(temp);
        }
    }

void print()
{
    queue *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main()
{
    cout<<"enter the maximum number"<<endl;
    cin>>maxi;
    insert(1);
    insert(2);
    insert(3);
    print();
}
