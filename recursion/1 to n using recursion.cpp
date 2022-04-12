#include<bits/stdc++.h>
using namespace std;
void printr(int a,int n)
{
   if(a>n)
   return;
   else
   {
       cout<<a<<endl;
       printr(a+1,n);
   }

}
int main()
{
    int n;
    cin>>n;
    printr(1,n);
}