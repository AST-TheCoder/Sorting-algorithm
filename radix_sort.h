#include<bits/stdc++.h>
using namespace std;

long long int getMax(long long int arr[], long long int n)
{
    long long int mx = arr[0];
    for (long long int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(long long int arr[], long long int n, long long int exp)
{
    long long int output[n];
    long long int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(long long int arr[], long long int n)
{
    long long int m = getMax(arr, n);
    for (long long int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}