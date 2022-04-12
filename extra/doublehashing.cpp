#include<bits/stdc++.h>
using namespace std;
struct myhash
{
    int bucket;
    int probekey;
    int *arr;
    myhash(int b,int c)
    {
        bucket=b;
        probekey=c;
        arr=new int[bucket];
        for(int i=0;i<bucket;i++)
            arr[i]=NULL;
    }
    void inserthash(int x)
    {
        int key1=x%bucket;
        int key2=probekey-(x%probekey);      //key1=(key1+key2)%bucket;
        if(arr[key1]==NULL)
            arr[key1]=x;
        else
        {
            while(arr[key1]!=NULL&&arr[key1]!=-1&&arr[key1]!=x)
            {
                key1=(key1+key2)%bucket;
            }
            arr[key1]=x;
        }
    }
     void searchhash(int x)
    {
        int key1=x%bucket;
        int key2=probekey-(x%probekey);
        int temp=key1;
        if(arr[key1]==x)
            cout<<"found"<<endl;
            else{
                int count=0;
                    key1=(key1+key2)%bucket;
                while(arr[key1]!=NULL&&key1!=temp)
                {
                    if(arr[key1]==x)
                    {
                        count++;
                        break;
                    }
                    key1=(key1+key2)%bucket;
                }
                if(count==0)
                    cout<<"not found"<<endl;
                else
                    cout<<"found"<<endl;
            }
    }
    void deletehash(int x)
    {
     int key1=x%bucket;
        int key2=probekey-(x%probekey);
        int temp=key1;
        if(arr[key1]==x)
        {
            arr[key1]=-1;
            cout<<"deleted"<<endl;
        }
        else
        {
            int count=1;
            key1=(key1+key2)%bucket;
            while(arr[key1]!=NULL&&key1!=temp)
            {
                if(arr[key1]==x)
                {
                    arr[key1]=-1;
                    count=0;
                    break;
                }
                key1=(key1+key2)%bucket;
            }
            if(count==0)
                cout<<"deleted"<<endl;
            else
                cout<<"cant delete not found"<<endl;
        }
    }
    void printhash()
    {
        for(int i=0;i<bucket;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};
int main()
{
    myhash h1(7,6);
    h1.inserthash(49);
    h1.inserthash(63);
    h1.inserthash(56);
    h1.inserthash(52);
    h1.inserthash(54);
    h1.inserthash(48);
    h1.searchhash(52);
    h1.deletehash(90);
    h1.printhash();
}
