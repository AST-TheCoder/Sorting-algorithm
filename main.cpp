#include "headers.h"

long long int arr[1000007],n,temp[1000007];
clock_t start_time,end_time;

void take_input(){
    freopen("input.txt","r",stdin);
    scanf("%lli",&n);
    for(int i=0;i<n;i++) scanf("%lli",&arr[i]);
}

void make_clone(){
    for(int i=0;i<n;i++) temp[i]=arr[i];
}

void check(string s){
    int flag=1;
    for(int i=1;i<n;i++){
        if(temp[i]<temp[i-1]) flag=0;
    }

    double time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
    cout<<s<<endl;
    if(flag) printf("Array is sorted!!! Time taken %lf sec\n\n",time_taken);
    else{
        //for(int i=0;i<n;i++) cout<<temp[i]<<" ";cout<<endl;
        printf("Array is not sorted!!!\n\n");
    }
}

int main()
{
    take_input();

    //Radix Sort
    make_clone();
    start_time=clock();
    radix_sort(temp,n);
    end_time=clock();
    check("Radix Sort");

    //Merge Sort
    make_clone();
    start_time=clock();
    merge_sort(temp,n);
    end_time=clock();
    check("Merge Sort");

    //Heap Sort
    make_clone();
    start_time=clock();
    heap_sort(temp,n);
    end_time=clock();
    check("Heap Sort");

    //AST Sort three
    make_clone();
    start_time=clock();
    ast_sort_three(temp,n);
    end_time=clock();
    check("AST Sort three");

    //AST Sort two
    make_clone();
    start_time=clock();
    ast_sort_two(temp,n);
    end_time=clock();
    check("AST Sort two");

    //AST Sort one
    make_clone();
    start_time=clock();
    ast_sort_one(temp,n);
    end_time=clock();
    check("AST Sort one");

    return 0;
}

// Test cases
// 10 675 10 1003 6275 89 12 811 9 1 10