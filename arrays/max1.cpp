#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
     for(int i=0;i<n;i++)
        cin>>arr[i];
     int count=0,ans=0;
     for(int i=0;i<n;i++)
     {
         if(arr[i]==1)
            count++;
         else
            {
                ans=max(ans,count);
         count=0;
         }
     }
     ans=max(ans,count);
     cout<<ans<<endl;
}
