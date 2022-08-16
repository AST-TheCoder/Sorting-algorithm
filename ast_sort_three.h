#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll next_index,val_len;

struct node_three{
    int val=0,chk=0;
    node_three* child[10];
};

void build_trie(node_three* root,ll arr[],ll length[],ll n){
    node_three* temp_node;
    for(ll i=0;i<n;i++){
        ll val=arr[i];
        ll len=val_len-length[i];
        temp_node=root;
        while(length[i]){
            ll v=0;
            if(!len){
                v=val-(val/10)*10;
                val/=10;
                length[i]--;
            }
            else len--;
            if(!(temp_node->chk&(1<<v))){
                temp_node->child[v]=new node_three();
                temp_node->chk|=(1<<v);
            }
            temp_node=temp_node->child[v];
            if(!length[i]) temp_node->val++;
        }
    }
}

void sort_array(node_three* root,ll arr[],ll val){
    while((root->val)--) arr[next_index++]=val;
    for(ll i=0;i<10;i++){
        if(!(root->chk&(1<<i))) continue;
        sort_array(root->child[i],arr,val*10+i);
    }
}

void ast_sort_three(ll arr[],ll n){
    node_three* root=new node_three();
    next_index=0;
    ll length[n];

    for(ll i=0;i<n;i++){
        ll val=arr[i],len=0;
        arr[i]=0;
        while(val){
            arr[i]=arr[i]*10+val%10;
            val/=10;
            len++;
        }
        val_len=max(val_len,len);
        length[i]=len;
    }

    //clock_t start_time,end_time;
    //start_time=clock();
    build_trie(root,arr,length,n);
    //end_time=clock();
    //double time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
    //cout<<time_taken<<endl;
    //start_time=clock();
    sort_array(root,arr,0);
    //end_time=clock();
    //time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
    //cout<<time_taken<<endl;
}