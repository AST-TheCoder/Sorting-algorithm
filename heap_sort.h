#include<bits/stdc++.h>
using namespace std;

void heapify(long long int arr[], long long int N, long long int i)
{
 
    long long int largest = i;
    long long int l = 2 * i + 1;
    long long int r = 2 * i + 2;
 
    if (l < N && arr[l] > arr[largest]) largest = l;
    if (r < N && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heap_sort(long long int arr[], long long int N)
{

    for (long long int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (long long int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}