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
    void insert(int x)
    {
        arr[size]=x;
        size++;
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
    void buildheap()
    {
        for(int i=parent(size-1);i>=0;i--)
        {
            minheapify(i);
        }
    }
};

int main()
{
    minheap mp(10);
    mp.insert(10);
     mp.insert(5);
      mp.insert(20);
       mp.insert(2);
        mp.insert(4);
         mp.insert(8);
    mp.buildheap();
}