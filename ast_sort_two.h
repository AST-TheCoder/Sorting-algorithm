#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> temp_sort;
ll pos;

struct node{
    int val=0;
    node* child[10]={NULL};
};

void build(node* root,ll arr[],ll n, ll exp){
    for(ll i=0;i<n;i++){
        ll val=arr[i];
        node* temp_node=root;
        for(ll j=exp;j;j/=10){
            ll v=val/j;
            val%=j;
            if(temp_node->child[v]==NULL) temp_node->child[v]=new node();
            temp_node=temp_node->child[v];
            temp_node->val++;
        }
    }
}

void find_sorted_array(node* root,ll val){

    ll flag=0;
    for(ll i=0;i<10;i++){
        if(root->child[i]==NULL) continue;
        flag=1;
        find_sorted_array(root->child[i],val*10+i);
    }

    if(!flag){
        while(--root->val){
            temp_sort[pos++]=val;
        }
    }
}

void ast_sort_two(ll arr[],ll n){
    node* root=new node();
    temp_sort.resize(n);
    ll max_val=0;
    for(ll i=0;i<n;i++) max_val=max(max_val,arr[i]);
    if(!max_val) return;
    ll exp=(ll)pow(10,(ll)log10(max_val));

    build(root,arr,n,exp);
    find_sorted_array(root,0);
    for(ll i=0;i<n;i++) arr[i]=temp_sort[i];
}