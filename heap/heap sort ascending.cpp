#include<bits/stdc++.h>
using namespace std;
struct maxheap
{
    int size;
    maxheap(int i)
    {
        size=i;
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
    void printheap(int arr[])
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    void maxheapify(int arr[],int n,int i)
    {
        int lt=lchild(i);
        int rt=rchild(i);
        int greater=i;
        if(lt<n&&arr[i]<arr[lt])
        {
            greater=lt;
        }
        if(rt<n&&arr[greater]<arr[rt])
        {
            greater=rt;
        }
        if(greater!=i)
        {
            swap(arr[i],arr[greater]);
            maxheapify(arr,n,greater);
        }
    }
    void buildheap(int arr[],int n)
    {
        for(int i=parent(n-1);i>=0;i--)
        {
            maxheapify(arr,n,i);
        }
    }
    void heapsort(int arr[],int n)
    {
        buildheap(arr,n);
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            maxheapify(arr,i,0);
        }
    }
};
int main()
{
    int arr[]={50,20,10,4,15};
    maxheap mh(5);
    
    mh.heapsort(arr,5);
    mh.printheap(arr);
}