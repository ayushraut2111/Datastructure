#include<bits/stdc++.h>
using namespace std;
struct graph         //undirectional graph
{
    vector<int>*v;
    int size;
    graph(int i)
    {
        v=new vector<int>[i];
        size=i;
    }
    void addvertex(int i,int j)
    {
        v[i].push_back(j);
        v[j].push_back(i);
    }
    void printgraph()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                cout<<i<<" "<<v[i][j]<<endl;
            }
        }
    }
};
int main()
{
    graph g(3);
    g.addvertex(0,1);
    g.addvertex(1,2);
    g.printgraph();
}