#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int>s1;
    cout<<"enter the number of 1st array"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s1.insert(a[i]);
    }
    cout<<"enter the number of 2nd array"<<endl;
    int f;
    cin>>f;
    int b[f];
    for(int i=0;i<f;i++)
    {
        cin>>b[i];
    }
    int count=0;
    
    for(int i=0;i<f;i++)
    {
        if(s1.find(b[i])!=s1.end())
        {
            count++;
            s1.erase(b[i]);
            break;
        }
        
    }
    cout<<count<<endl;
}


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int>s1,s2;
    cout<<"enter the number of 1st array"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        s1.insert(d);
    }
    cout<<"enter the number of 2nd array"<<endl;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int d;
        cin>>d;
        s2.insert(d);
    }
      int count=0;
      unordered_set<int>::iterator it1=s1.begin();
      while(it1!=s1.end())
      {
          unordered_set<int>::iterator it2=s2.begin();
          while(it2!=s2.end())
          {
              if(*it1==*it2)
              {
                  count++;
                  break;
              }
              it2++;
          }   
          it1++;
      }
      cout<<count<<endl;
}
*/