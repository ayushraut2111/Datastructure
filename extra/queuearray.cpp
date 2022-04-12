#include<iostream>
using namespace std;
int queue[100],front=-1,rear=-1,maxi;
void insert(int val)
{
    if(rear==maxi-1)
        cout<<"overflow"<<endl;
else
{
    if(front==-1&&rear==-1)
    {
        front+=1;
        rear+=1;
    }
    else
        rear=rear+1;
    queue[rear]=val;
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
    }
}
void print()
{
    for(int i=front;i<maxi;i++)
        cout<<queue[i]<<endl;
}
int main()
{
    cout<<"enter the maximum number"<<endl;
    cin>>maxi;
    insert(1);
    insert(2);
    insert(3);
    deletei();
    print();
}
