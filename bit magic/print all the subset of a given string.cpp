#include <bits/stdc++.h>
using namespace std;
void cal(string s, vector<vector<char>> &v)
{
    int n = s.length();
    for (int i = 0; i <= pow(2, n) - 1; i++)     //if there is a string of length n then there could be 2^n-1 no. of subsets
    {
        int f = i;
        if (i == 0)
        {
            vector<char> temp;
            temp.push_back(' ');
            v.push_back(temp);
            continue;
        }
        int count = 0;
        vector<char> temp;
        while (f != 0)
        {
            if (f & 1 == 1)
                temp.push_back(s[count]); //if 1 comes at first place then print 1st word of the array  if 1 comes at 2nd then print 2nd word and so on
            f = f >> 1;
            count++; // do count++ to increase the position of string (place of the string)
        }
        v.push_back(temp);
    }
}
int main()
{
    string s;
    cin >> s;
    vector<vector<char>> v;
    cal(s, v);
    for (auto x : v)
    {
        for (auto c : x)
        {
            cout << c;
        }
        cout << endl;
    }
}