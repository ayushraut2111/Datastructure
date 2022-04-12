#include<bits/stdc++.h>
using namespace std;
	string removeDups(string s) 
	{
	    int arr[256]={0};
	    for(int i=0;i<s.length();i++)
	    {
	        if(arr[s[i]]!=0)
	        {
                cout<<s[i]<<endl;
                s[i]='0';
            }
	        else
	        arr[s[i]]++;
	}
    cout<<s.find('0')<<endl;
    while(s.find('0')!=-1)
    {
        s.erase(s.find('0'),1);
    }
	    return s;

	
	}
 int main()
 {
     string s;
     cin>>s;
     s=removeDups(s);
     cout<<s;
 }