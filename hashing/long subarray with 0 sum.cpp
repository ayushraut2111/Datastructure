#include<bits/stdc++.h>
using namespace std;
int maxlen(int a[],int n)
{
    unordered_map<int,int>s;
     int pre_sum=0,res=0;
     for(int i=0;i<n;i++)
     {
           pre_sum+=a[i];
           if(pre_sum==0)
           res=i+1;
           if(s.find(pre_sum)==s.end())
           s.insert({pre_sum,i});
           if(s.find(pre_sum)!=s.end())
           {
               res=max(res,i-s[pre_sum]);
           }
     }
     return res;
}
 int main()
 {
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     cin>>a[i];
     /*unordered_map<int,int>s;
     int pre_sum=0,res=0;
     for(int i=0;i<n;i++)
     {
           pre_sum+=a[i];
           if(pre_sum==0)
           res=i+1;
           if(s.find(pre_sum)==s.end())
           s.insert({pre_sum,i});             // map is used to store the presum and their index  and if there is same      
           if(s.find(pre_sum)!=s.end())       // presum for 2 index then the leftmost is considered because from the current position leftmost will be the longest
           {
               res=max(res,i-s[pre_sum]);
           }
     }
     cout<<res<<endl; */
     int res=maxlen(a,n);
     cout<<res<<endl;
 }