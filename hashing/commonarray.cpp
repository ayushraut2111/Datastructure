#include<bits/stdc++.h>
using namespace std;
vector<int> common_element( vector<int>v1, vector<int>v2)
{
    unordered_map<int,int>m1,m2;
    for(int i=0;i<v1.size();i++)
    {
        if(m1.find(v1[i])!=m1.end())
        m1[v1[i]]++;
        else
        m1.insert({v1[i],1});
    }
    for(int i=0;i<v2.size();i++)
    {
        if(m2.find(v2[i])!=m2.end())
        m2[v2[i]]++;
        else
        m2.insert({v2[i],1});
    }
    vector<int>v3;
    unordered_map<int,int>::iterator it1=m1.begin();
    while(it1!=m1.end())
    {
        if(m2.find(it1->first)!=m2.end())
        {
            for(int i=0;i<min(it1->second,m2[it1->first]);i++)
            {
                v3.push_back(it1->first);
            }
        }

        it1++;
    }
    sort(v3.begin(),v3.end());
    return v3;
}
 int main()
 { 
   vector<int>v1,v2;
      int n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         v1.push_back(x);
     }
     int m;
     cin>>m;
     for(int i=0;i<m;i++)
     {
         int x;
         cin>>x;
         v2.push_back(x);
     }
     vector<int>v3=common_element(v1,v2);
     for(int i=0;i<v3.size();i++)
     {
         cout<<v3[i]<<endl;
     }
 }



 /*
    / list<int>l1,l2,l3;
     int n;
     cin>>n;
     for(int i=0;i<n;i++)
     {
         int x;
         cin>>x;
         l1.push_back(x);
     }
     int m;
     cin>>m;
     for(int i=0;i<m;i++)
     {
         int x;
         cin>>x;
         l2.push_back(x);
     }
     list<int>::iterator it=l1.begin();
     while(it!=l1.end())
     {
         list<int>::iterator it1=find(l2.begin(),l2.end(),*it);
         if(it1!=l2.end())
         {
             l3.push_back(*it);
             l2.erase(it1);
         }
         it++;
     }
     l3.sort();
     list<int>::iterator it3=l3.begin();
     while(it3!=l3.end())
     {
         cout<<*it3<<endl;
         it3++;
     }
     */