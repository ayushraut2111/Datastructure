#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the number of arrays"<<endl;
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int>m;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        int count=0;
        unordered_map<int,int>::iterator it=m.begin();
        while(it!=m.end())
        {
            if(arr[i]==it->first)
            {
                it->second++;
                count++;
                break;
            }
            it++;
        }
        if(count==0)
        m.insert({arr[i],1});
    }
     unordered_map<int,int>::iterator it=m.begin();
        while(it!=m.end())
        {
            cout<<it->first<<" "<<it->second<<endl;
            it++;
        }
}