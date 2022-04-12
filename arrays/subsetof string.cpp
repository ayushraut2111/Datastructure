#include<iostream>
#include<math.h>
using namespace std;
int countset(int n,int x,int y,int z)
{
    static int count=0;
    if(n<1)
        return 0;
    int m=min(min(x,y),z);
    countset(n-m,x,y,z);
    count++;
    return count;
}
int main()
{
    cout<<countset(23,12,9,11);
}
