#include<bits/stdc++.h>
using namespace std;
int cbr(string s1,string s2)
{
    s1=s1+s1;
    return s1.find(s2);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int res=cbr(s1,s2);
    if(res==-1)
    cout<<"can't form";
    else
    cout<<"yes it can be formed"<<endl;
}