#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e15
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;

struct line{
    int to;
    ll ft, p, d;
};

ll wait(ll t0, ll a, ll nt){
    if(nt-t0<0) return t0-nt;
    ll x = (nt-t0)/a;
    if(t0+a*x==nt) return 0;
    else return t0+a*(x+1)-nt;
}

ll Dijklstra(int n, vector<vector<line>> G, ll st, ll limit){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq;
    vector<bool> isconf(n, false);
    pq.push({st, 0});

    while(!pq.empty()){
        ll nt = pq.top().first;
        int pv = pq.top().second;
        pq.pop();
        if(pv==n-1) return nt;
        isconf[pv] = true;

        for(auto nv:G[pv]){
            ll nxt = nt + wait(nv.ft, nv.p, nt) + nv.d;
            if(isconf[nv.to] || nxt>limit) continue;
            pq.push({nxt, nv.to});
        }
    }
    return INF;
}

int main(){
    int n, m; ll s; cin>>n>>m>>s;
    vector<vector<line>> G(n);
    for(int i=0; i<m; i++){
        int u, v; ll a, b, c; cin>>u>>v>>a>>b>>c;
        G[u].push_back({v, a, b, c});
    }
    ll left = -1, right = s, mid = (left+right)/2;
    while(right-left>1){
        mid = (left+right)/2;
        if(Dijklstra(n, G, mid, s) > s) right = mid;
        else left = mid;
    }
    if(left<0) cout << "impossible" << endl;
    else if(Dijklstra(n, G, right, s) > s) cout << left << endl;
    else cout << right << endl;
    return 0;
}