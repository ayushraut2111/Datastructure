#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int temp[m][n],i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            temp[j][i]=a[i][j];
        }
    }
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=temp[i][j];
        }
}
 for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           cout<<a[i][j]<<" ";
        }
        cout<<endl;
}
}
