#include<bits/stdc++.h>
using namespace std;
struct minheap
{
    int *arr;
    int cap;
    int size;
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
    void minheapify(int i,int s)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int smallest=i;
        if(lt<s&&arr[i]>arr[lt])
        {
            smallest=lt;
        }
        if(rt<s&&arr[smallest]>arr[rt])
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minheapify(smallest,s);
        }
    }
    void buildheap()
    {
        for(int i=parent(size-1);i>=0;i--)
        {
            minheapify(i,size);
        }
    }
    void heapsort()
    {
        buildheap();
        for(int i=size-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            minheapify(0,i);
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
    mp.insert(10);
     mp.insert(5);
      mp.insert(20);
       mp.insert(2);
        mp.insert(4);
         mp.insert(8);
    mp.heapsort();
    mp.printheap();
}