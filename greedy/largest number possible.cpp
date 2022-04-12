#include<bits/stdc++.h>
using namespace std;
string largestposs(int n,int s)
{
    if(s>9*n)
    return "-1";
    if(s==0)
    {
        if(n==1)
        return "0";
        else
        return "-1";
    }
    string res;
    for(int i=0;i<n;i++)
    res+="0";
    int i=0;
    int k=n;
    while(s!=0&&k>0)
    {
        if(s>=9)
        {
            res[i]='9';
            s-=9;
            i++;
            k--;
        }
        else
        {
            char x=s+48;
            res[i]=x;
            s=0;
            k--;
        }
    }
    return res;
}
int main()
{
    int n,s;
    cin>>n>>s;
    cout<<largestposs(n,s);
}