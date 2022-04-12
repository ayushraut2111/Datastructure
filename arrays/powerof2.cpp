#include<iostream>
using namespace std;
 int main()
 {
     int n;
     cin>>n;
     int count=0;
     while(n>0&&count<=1)
     {
         if(n&1==1)
            count++;
         n=n>>1;
     }
     if(count!=1)
        cout<<"No"<<endl;
     else
        cout<<"yes"<<endl;
 }
