#include<bits/stdc++.h>
using namespace std;
void permutation(string s,int i)
{
    if(i==s.length()-1)
    cout<<s<<endl;
    for(int j=i;j<s.length();j++)
    {
        swap(s[i],s[j]);
        permutation(s,i+1);
        swap(s[j],s[i]);
    }
}
int main()
{
    string s;
    cin>>s;
    permutation(s,0);
}