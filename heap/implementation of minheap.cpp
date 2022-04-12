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
    void deletekey(int i)
    {
        arr[i]=INT_MIN;
        while(i!=0&&arr[i]<arr[parent(i)])
        {
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
        swap(arr[0],arr[size-1]);
        size--;
        minheapify(0);

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
