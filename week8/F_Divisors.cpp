#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<ll> pm;

//n!は素因数pを何個持つか
ll pmnum(ll n, ll p){
    ll rt = 0;
    for(ll i=p; i<=n; i*=p) rt += (n/i);
    return rt;
}
//nまでの素数を列挙
void prime(ll n){
    vector<bool> isprime(n+1, true);
    for(ll i=2; i<=n; i++){
        if(!isprime[i]) continue;
        pm.push_back(i);
        for(ll j=i*i; j<=n; j+=i) if(isprime[j]) isprime[j] = false;
    }
    return;
}

int main(){
    ll maxnum = 431; prime(maxnum);
    int c = (int)pm.size();

    vector<vector<ll>> table(maxnum+1, vector<ll>(c,0)); //素因数の個数のテーブル
    for(ll i=2; i<=maxnum; i++){
        for(ll j=0; j<c; j++){
            table[i][j] = pmnum(i, pm[j]);
        }
    }

    ll n, k;
    while(cin>>n>>k){
        ll p = n-k;
        ll ans = 1;
        for(ll i=0; i<c; i++){
            if(table[n][i]==0) break;
            ans *= (table[n][i]-table[p][i]-table[k][i]+1);
        }
        cout << ans << endl;
    }
    return 0;
}