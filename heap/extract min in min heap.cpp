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
    void minheapify(int i)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int smallest=i;
        if(lt<size&&arr[i]>arr[lt])
        {
            smallest=lt;
        }
        if(rt<size&&arr[smallest]>arr[rt])
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minheapify(smallest);
        }
    }
    int extractminheap()
    {
        if(size==0)
        return INT_MIN;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        minheapify(0);
        return arr[size];
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
cout<<mp.extractminheap()<<endl;
}
