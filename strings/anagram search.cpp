#include<bits/stdc++.h>
using namespace std;
int anasearch1(string s1,string s2)
{
    int i;
    sort(s2.begin(),s2.end());
    for(i=0;i<=s1.length()-s2.length();i++)
    {
       string s3=s1.substr(i,s2.length());
       sort(s3.begin(),s3.end());
       if(s2==s3)
       return 1;
    }
    return 0;

}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int x=anasearch1(s1,s2);
    if(x==0)
    cout<<"no"<<endl;
    else
    cout<<"yes"<<endl;
}