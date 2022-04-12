#include<bits/stdc++.h>
using namespace std;
struct maxheap
{
    int *arr;
    int size;
    int cap;
    maxheap(int x)
    {
        cap=x;
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
    void insert()
    {
        for(int i=0;i<cap;i++)
        {
            cin>>arr[i];
            size++;
        }
    }
    void printheap()
    {
        for(int i=0;i<cap;i++)
        cout<<arr[i]<<endl;
    }
    void maxheapify(int c,int i)    //
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int greater=i;
        if(arr[lt]>arr[greater]&&lt<c)
        {
            greater=lt;
        }
        if(arr[rt]>arr[greater]&&rt<c)
        {
            greater=rt;
        }
        if(i!=greater)
        {
            swap(arr[i],arr[greater]);
            maxheapify(c,greater);
        }
    }
    void buildheap()        //
    {
        for(int i=parent(cap-1);i>=0;i--)
        {
            maxheapify(cap,i);
        }
    }
    void heapsort()    //
    {
        buildheap();
        for(int i=cap-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            maxheapify(i,0);
        }
    }
};
int main()
{
    maxheap mh(5);
    mh.insert();
    mh.printheap();
    mh.heapsort();
    mh.printheap();
}