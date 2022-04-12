#include <bits/stdc++.h>
using namespace std;
void insertsort(int a[], int n) // in insertion sort we place key to its right position in every iteration by compairing it with all the elements before it
{
    int i, j, key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertsort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}