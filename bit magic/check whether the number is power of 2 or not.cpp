#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "no";
        return 0;
    }
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
            count++;
        n = n >> 1;
    }
    if (count == 1)
        cout << "yes";
    else
        cout << "no";
}