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
    void insert(int x)
    {
        arr[size]=x;
        size++;
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
    void buildheap()
    {
        for(int i=parent(size-1);i>=0;i--)
        {
            maxheapify(i);
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
     maxheap mp(10);
    mp.insert(10);
     mp.insert(5);
      mp.insert(20);
       mp.insert(2);
        mp.insert(4);
         mp.insert(8);
    mp.buildheap();
    mp.printheap();
}