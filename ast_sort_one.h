#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void ast_sort_one_rec(vector<ll>& arr,ll n,ll exp){
    if(!exp) return;
    ll cnt[10]={0},len[10];
    for(ll i=0;i<n;i++) cnt[(arr[i]/exp)%10]++;
    vector<ll> temp[10];
    for(ll i=0;i<10;i++){
        temp[i].resize(cnt[i]);
        len[i]=cnt[i];
    }
    for(ll i=0;i<n;i++){
        ll id=(arr[i]/exp)%10;
        cnt[id]--;
        temp[id][cnt[id]]=arr[i];
        //cout<<exp<<" "<<id<<" "<<temp[id][cnt[id]]<<" "<<cnt[id]<<endl;
    }
    //cout<<endl;
    for(ll i=0,j=0;i<10;i++){
        if(!len[i]) continue;
        ast_sort_one_rec(temp[i],len[i],exp/10);
        for(ll id=0;id<len[i];id++,j++){
            arr[j]=temp[i][id];
        }
    }
}

void ast_sort_one(ll arr[],ll n){
    vector<ll> v(n);
    ll max_val=0;

    for(ll i=0;i<n;i++){
        max_val=max(max_val,arr[i]);
        v[i]=arr[i];
    }
    if(!max_val) return;
    ll exp=(ll)pow(10,(ll)log10(max_val));
    
    ast_sort_one_rec(v,n,exp);
    for(ll i=0;i<n;i++) arr[i]=v[i];
}