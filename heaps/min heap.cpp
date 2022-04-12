#include<bits/stdc++.h>
using namespace std;
struct minheap
{
    int *arr;
    int size;
    int cap;
    minheap(int x)
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
    void insertheap(int x)
    {
        if(size==cap)
        return ;
        arr[size]=x;
        int i=size;
        size++;
        while(arr[i]<arr[parent(i)]&&i!=0)
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
        
    }
    void minheapify(int i)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int smallest=i;
        if(arr[lt]<arr[smallest]&&lt<size)
        {
            smallest=lt;
        }
        if(arr[rt]<arr[smallest]&&rt<size)
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minheapify(smallest);
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
    minheap mh(3);
    mh.insertheap(3);
    mh.insertheap(56);
    mh.insertheap(-1);
    mh.printheap();
    mh.printheap();
    mh.minheapify(0);
    mh.printheap();

}