 #include<bits/stdc++.h>
 using namespace std;
 int fact(int n)
 {
     if(n==1)
     return 1;
     return n*fact(n-1);

 }
 int lrank(string s)
 {
     int res=0;
     for(int i=0;i<s.length()-1;i++)
     {
         int count=0;
         int x=s.length()-i-1;
         for(int j=i+1;j<s.length();j++)
         {
             if(s[j]<s[i])
             count++;
         }
         res+=count*fact(x);
     }
     return res+1;
 }
 int main()
 {
     string s;
     cin>>s;
     int n=lrank(s);
     cout<<n<<endl;

 }