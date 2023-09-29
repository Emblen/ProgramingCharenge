#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e15
using namespace std;
using ll=long long;

struct edge{
    int to;
    ll l;
};
struct info{
    ll maxbt, cost;
    int v;
    bool operator<(const info& right) const{
        return cost>right.cost;
    }
};

pair<ll, ll> Dijkstra(int n, vector<vector<edge>> G, ll limitbt){
    priority_queue<info> pq;
    vector<bool> isconf(n, false);
    ll dist = -1, bt = -1; int p = -1;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        dist = pq.top().cost;
        bt = pq.top().maxbt;
        p = pq.top().v;

        if(p==n-1) return {dist, bt};

        pq.pop();
        if(isconf[p]) continue;
        isconf[p] = true;

        for(auto v:G[p]){
            if(isconf[v.to] || v.l>limitbt) continue;
            pq.push({max(bt, v.l), dist+v.l, v.to});
        }
    }
    return {INF, INF};
}

int main(){
    int n, m, x; cin>>n>>m>>x;
    vector<vector<edge>> G(n);
    for(int i=0; i<m; i++){
        int a, b, c; cin>>a>>b>>c;
        a--; b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    ll left = 0, right = INF;
    pair<ll, ll> rx = Dijkstra(n, G, right);
    ll mindist = rx.first; 
    right = rx.second;
    ll allow = mindist + ll((double)mindist*x/(double)100);
 
    ll mid = (left+right)/2;
    while(right-left>1){
        mid = (left+right)/2;
        pair<ll, ll> rv = Dijkstra(n, G, mid);
        mindist = rv.first;
        if(mindist>allow) left = mid;
        else right = mid;
    }
    if(Dijkstra(n, G, left).first>allow) cout << right << endl;
    else cout << left << endl;
    return 0;
}