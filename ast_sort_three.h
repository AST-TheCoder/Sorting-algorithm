#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll next_index;

struct node_three{
    int val=0;
    node_three* child[10]={NULL};
};

void build_trie(node_three* root,ll arr[],ll n){
    node_three* temp_node;
    for(ll i=0;i<n;i++){
        ll val=0;

        while(arr[i]){
            val=val*10+arr[i]%10;
            arr[i]/=10;
        }

        temp_node=root;
        while(val){
            ll v=val%10;
            val/=10;
            if(temp_node->child[v]==NULL) temp_node->child[v]=new node_three();
            temp_node=temp_node->child[v];
            if(!val) temp_node->val++;
        }
    }
}

void sort_array(node_three* root,ll arr[],ll val){

    while((root->val)--) arr[next_index++]=val;
    for(ll i=0;i<10;i++){
        if(root->child[i]==NULL) continue;
        sort_array(root->child[i],arr,val*10+i);
    }
}

void ast_sort_three(ll arr[],ll n){
    node_three* root=new node_three();
    next_index=0;

    build_trie(root,arr,n);
    sort_array(root,arr,0);
}