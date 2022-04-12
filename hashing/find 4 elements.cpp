#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int n;
     cin>>n;
     vector<int>v;
     for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         v.push_back(x);
     }
     sort(v.begin(),v.end());
     int k;
     cin>>k;
     int i,j,l,r;
     for(i=0;i<n-3;i++)
     {
         for(j=i+1;j<n-2;j++)
         {
             l=j+1;
             r=n-1;
             while(l<r)
             {
                 if((v[i]+v[j]+v[l]+v[r])==k)
                 {
                     cout<<v[i]<<" "<<v[j]<<" "<<v[l]<<" "<<v[r]<<endl;
                     l++;r--;
                 }
                 else if((v[i]+v[j]+v[l]+v[r])>k)
                 r--;
                 else
                 l++;
             }
         }
     }
 }