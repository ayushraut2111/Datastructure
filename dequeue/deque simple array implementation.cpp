#include<bits/stdc++.h>
using namespace std;
struct dequeue
{
    int *arr;
    int size,cap;
    dequeue(int n)
    {
        cap=n;
        size=0;
        arr=new int[cap];
    }
    void insertrear(int x)
    {
        if(size==cap)
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            arr[size]=x;
            size++;
        }
    }
    void insertfront(int x)
    {
        if(size==cap)
        {
            cout<<"overflow"<<endl;
        }
        else
        {
            for(int i=size-1;i>=0;i--)          //shifting all array one position ahead to make space for inserting at the first postion
            {
                arr[i+1]=arr[i];
            }
            arr[0]=x;             //front will always be at 0 and rear will be at size-1(because we are incrementing size+1 after every insertion)
            size++;
        }
    }
    void deletefront()
    {
        if(size==0)
        {
            cout<<"underflow"<<endl;
        }
        else 
        {
            for(int i=0;i<size-1;i++)
            arr[i]=arr[i+1];
            size--;
        }
    }
    void deleterear()
    {
        if(size==0)
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            size--;
        }
    }
    int getfront()
    {
         if(size==0)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }   
        else
        return arr[0];
    }
    int getrear()
    {
         if(size==0)
        {
            cout<<"underflow"<<endl;
            return INT_MAX;
        }   
        else
        return arr[size-1];
    }
    bool isfull()
    {
        return (size==cap);
    }
    bool isempty()
    {
        return (size==0);
    }
};
int main()
{
    dequeue dq(4);
    dq.insertfront(1);
    
    
    }