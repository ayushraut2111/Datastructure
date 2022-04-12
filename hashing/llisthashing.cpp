#include<bits/stdc++.h>
using namespace std;
struct myhash
{
    int bucket;
    list<int>*table;
    myhash(int b)
    {
        bucket=b;
        table=new list<int>[bucket];
    }
    void inserthash(int x)
    {
        int key=x%bucket;
        table[key].push_back(x);
    }
    void searchhash(int x)
    {
        int count=0;
        int key=x%bucket;
             list<int>::iterator it=table[key].begin();
            while(it!=table[key].end())
            {
                if(x==*it)
                    count++;
                it++;
            }
        if(count==0)
            cout<<"not found"<<endl;
        else
            cout<<"found"<<endl;
    }
    void deletehash(int x)
    {
        int key=x%bucket;
        table[key].remove(x);
    }
    void printhash()
    {
        for(int i=0;i<bucket;i++)
        {
            list<int>::iterator it=table[i].begin();
            while(it!=table[i].end())
            {
                cout<<*it<<" ";
                it++;
            }
            cout<<endl;
        }
    }
};
int main()
{
    myhash h1(7);
    h1.inserthash(50);
    h1.inserthash(21);
    h1.inserthash(58);
    h1.inserthash(17);
    h1.inserthash(15);
    h1.inserthash(49);
    h1.inserthash(56);
    h1.inserthash(22);
    h1.inserthash(23);
    h1.inserthash(25);
   h1.deletehash(25);
    h1.printhash();
}
