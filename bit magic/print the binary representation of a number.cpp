#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    while (n != 0)
    {
        v.push_back(n & 1);
        n = n >> 1;
    }
    reverse(v.begin(), v.end());
    for (auto x : v)
        cout << x;
}