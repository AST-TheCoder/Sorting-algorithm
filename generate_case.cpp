#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll randval(ll beg,ll len){
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    mt19937 generator(seed1);
	uniform_int_distribution<ll> distribution(beg, len);

    return distribution(generator);
}

int main()
{
    freopen("inputs/input10.txt","w",stdout);
    ll n=100;
    cout<<n<<endl;
    for(ll i=0;i<n;i++){
        cout<<1000000000000000000+n-i<<" ";
    }cout<<endl;
}