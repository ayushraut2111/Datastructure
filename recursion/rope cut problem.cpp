#include<bits/stdc++.h>
using namespace std;
int ropecut(int a,int b,int c,int n)
{
  if(n==0)
  return 0;
  if(n<0)
  return -1;
  int x=max(ropecut(a,b,c,n-a),max(ropecut(a,b,c,n-b),ropecut(a,b,c,n-c)));
 if(x==-1)
 return -1;
 else return x+1;
}
int main()
{
  int n,a,b,c;
  cin>>a>>b>>c>>n;
  cout<<ropecut(a,b,c,n);
}