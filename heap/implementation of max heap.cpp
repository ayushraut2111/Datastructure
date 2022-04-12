#include<bits/stdc++.h>
using namespace std;
struct maxheap
{
    int *arr;
    int cap;
    int size;
    maxheap(int c)
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
        int i=size-1;
        while(i!=0&&arr[i]>arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    void printheap()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    void maxheapify(int i)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int greater=i;
        if(lt<size&&arr[i]<arr[lt])
        {
            greater=lt;
        }
        if(rt<size&&arr[greater]<arr[rt])
        {
            greater=rt;
        }
        if(greater!=i)
        {
            swap(arr[i],arr[greater]);
            maxheapify(greater);
        }
    }
    void deletekey(int i)
    {
        arr[i]=INT_MAX;
        while(i!=0&&arr[i]>arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }   
        swap(arr[0],arr[size-1]);
        size--;
        maxheapify(0);
    }
};
int main()
{
    maxheap mp(10);
mp.insertheap(5);
mp.insertheap(9);
mp.insertheap(8);
mp.insertheap(12);
mp.insertheap(14);
mp.insertheap(20);
mp.insertheap(40);
mp.printheap();
mp.deletekey(3);
mp.printheap();
}