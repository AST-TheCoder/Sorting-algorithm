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
    freopen("inputs/input07.txt","w",stdout);
    ll n=randval(1,1000000);
    cout<<n<<endl;
    for(ll i=0;i<n;i++){
        cout<<randval(1,10000000)<<" ";
    }cout<<endl;
}