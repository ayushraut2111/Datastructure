#include<bits/stdc++.h>
using namespace std;
vector<int> psearch(string s,string s1)
{
    vector<int> v;
    while(s.find(s1)!=-1)
    {
        v.push_back(s.find(s1));
        s[s.find(s1)]=NULL;
    }
    return v;
}
int main()
 {
     string s,s1;
     cin>>s>>s1;     
     vector<int>v=psearch(s,s1);
     if(v.empty())
     cout<<"no pattern";
     else{
     for(int i=0;i<v.size();i++)
     cout<<v[i]<<endl;
     }
 }
     