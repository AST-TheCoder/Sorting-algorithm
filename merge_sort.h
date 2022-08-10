#include <bits/stdc++.h>
using namespace std;

void merge_sort_rec(long long int arr[],int low,int high){
    if(low==high) return;
    int mid=(low+high)/2;

    merge_sort_rec(arr,low,mid);
    merge_sort_rec(arr,mid+1,high);

    vector<long long int> temp(high-low+1);
    for(int i=low,j=mid+1,idx=0;i<=mid || j<=high;idx++){
        if(i>mid){
            temp[idx]=arr[j];
            j++;
        }
        else if(j>high){
            temp[idx]=arr[i];
            i++;
        }
        else if(arr[i]<=arr[j]){
            temp[idx]=arr[i];
            i++;
        }
        else{
            temp[idx]=arr[j];
            j++;
        }
    }
    for(int i=low;i<=high;i++) arr[i]=temp[i-low];
}

void merge_sort(long long int arr[],int n){
    merge_sort_rec(arr,0,n-1);
}