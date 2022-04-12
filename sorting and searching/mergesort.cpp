#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int beg, int mid, int end)
{
    int i, j, k, n1, n2;
    n1 = mid - beg + 1; // counting the number of elements in first half
    n2 = end - mid;     // counting number of elements into 2nd half
    int h1[n1];         // making a temporary array for 1st half for comparision
    int h2[n2];         // making a temporary array for 2nd half for comparision
    for (i = 0; i < n1; i++)
        h1[i] = a[beg + i]; // copying the elements of first half into temporary array
    for (i = 0; i < n2; i++)
        h2[i] = a[mid + 1 + i]; // copying the elements of 2nd half into temporary array
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2) // run a loop until any elements become empty
    {
        if (h1[i] <= h2[j]) // if element of 1st half of the array is smaller then copy it into main array
        {
            a[k] = h1[i];
            i++;
        }
        else
        {
            a[k] = h2[j]; // else copy the element of 2nd half into main array
            j++;
        }
        k++;
    }
    while (i < n1) // if 2nd half become empty then copy the remaining element of 1st array at the last position of main array
    {
        a[k] = h1[i];
        i++;
        k++;
    }
    while (j < n2) // if 1st half become empty then copy the remaining element of 2nd array at the last position of main array
    {
        a[k] = h2[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergesort(a, beg, mid);     // calling mergesort for 1st half
        mergesort(a, mid + 1, end); // calling mergesort for second half
        merge(a, beg, mid, end);    // after dividing both array merge two sorted subarray
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}