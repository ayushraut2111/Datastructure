#include<bits/stdc++.h>
using namespace std;
struct minheap
{
    int *arr;
    int size;
    int cap;
    minheap(int c)
    {
        cap=c;
        arr=new int[cap];
        size=0;
    }
    int lchild(int i)
    {
        return 2*i+1;
    }
    int rchild(int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    void insertheap(int x)
    {
        if(size==cap)
        return ;
        arr[size]=x;
        size++;
        int p=size-1;
        while(arr[p]<arr[parent(p)]&&p!=0)
        {
            swap(arr[p],arr[parent(p)]);
            p=parent(p);
        }
    }
    void decreasekey(int i,int x)
    {
        arr[i]=x;
        while(i!=0&&arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void printheap()
    {
        for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;
    }
};
int main()
{
    minheap mp(10);
mp.insertheap(10);
mp.insertheap(20);
mp.insertheap(15);
mp.insertheap(40);
mp.insertheap(50);
mp.insertheap(100);
mp.insertheap(25);
mp.insertheap(45);
mp.insertheap(12);
mp.decreasekey(3,6);
mp.printheap();
}
