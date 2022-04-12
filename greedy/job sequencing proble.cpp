#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first>p2.first;
}
int jsp(vector< pair<int,int> >v)
{
    sort(v.begin(),v.end(),cmp);
   int a[v.size()];
   bool b[v.size()];
   for(int i=0;i<v.size();i++)
   {
       b[i]=false;
       a[i]=0;
   }
   for(int i=0;i<v.size();i++)
   {
       if(b[v[i].second-1]==false)
       {
           a[v[i].second-1]=v[i].first;
           b[v[i].second-1]=true;
       }
       else
       {
           int j=v[i].second-1;
           while(b[j]==true&&i!=0)
           {
               j--;
           }
           if(j!=v[i].second-1)
           {
               a[j]=v[i].first;
           b[j]=true;
           }
       }
   }
   int ans=0;
   for(int i=0;i<v.size();i++)
   cout<<a[i]<<endl;
   for(int i=0;i<v.size();i++)
   ans+=a[i];
   return ans;

}
int main()
{
    int n;
    cin>>n;
     vector< pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        float a,b;
        cin>>a>>b;
        v.push_back({a,b});     //a=profit   b=deadline
    }
    cout<<jsp(v);
}