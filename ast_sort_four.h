#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll p[10],nxt_idx,idx[1025];
struct node_four{
    long long int val=0,len=0,cnt=0,chk=0,flag=-1;
    node_four* child[10];
};

void bld_trie(node_four* root,ll arr[],ll n,ll val_length){
    for(ll i=0;i<n;i++){
        node_four* curr_node=root;
        ll val=arr[i],len=val_length,cnt=1;
        if(!val){
            curr_node->flag=0;
            curr_node->cnt++;
            continue;
        }

        while(len!=1){
            len/=10;
            ll v=val/len;
            val%=len;
            if((curr_node->chk&p[v])==0){
                curr_node->child[v]=new node_four();
                curr_node->chk|=p[v];
                curr_node=curr_node->child[v];
                curr_node->len=len;
                curr_node->val=val;
                curr_node->cnt=cnt;
                if(len!=1) curr_node->flag=val/(len/10);
                else curr_node->flag=0;
                break;
            }
            curr_node=curr_node->child[v];
            if(curr_node->val==val){
                curr_node->cnt++;
                break;
            }

            if(len!=1 && curr_node->flag==val/(len/10) && val<curr_node->val){
                swap(curr_node->val,val);
                swap(curr_node->cnt,cnt);
            }
        }

    }
}

void sort_arr(node_four* root,ll arr[],ll val){
    while(root->chk){

        ll right_bit=(root->chk&(-(root->chk)));
        ll i=idx[right_bit];
        root->chk-=right_bit;

        if(root->flag<=i){
            ll v=val*root->len+root->val;
            while(root->cnt>0){
                root->cnt--;
                arr[nxt_idx++]=v;
            }
        }

        sort_arr(root->child[i],arr,val*10+i);
    }

    ll v=val*root->len+root->val;
    while(root->cnt>0){
        root->cnt--;
        arr[nxt_idx++]=v;
    }
}

void ast_sort_four(ll arr[],ll n){
    node_four* root=new node_four();
    ll max_val=0,val_length=1;
    nxt_idx=0;

    for(ll i=0;i<n;i++){
        max_val=max(max_val,arr[i]);
    }

    while(max_val){
        val_length*=10;
        max_val/=10;
    }
    p[0]=1;
    idx[1]=0;

    for(ll i=1;i<10;i++){
        p[i]=p[i-1]*2;
        idx[p[i]]=i;
    }
    

    // clock_t start_time,end_time;
    // start_time=clock();
    bld_trie(root,arr,n,val_length);
    // end_time=clock();
    // double time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
    // cout<<time_taken<<endl;
    // start_time=clock();
    sort_arr(root,arr,0);
    // end_time=clock();
    // time_taken=double(end_time-start_time)/double(CLOCKS_PER_SEC);
    // cout<<time_taken<<endl;
}