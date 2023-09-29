#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define vi vector<int>
#define vb vector<bool>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

struct edge{
    int to, l;
    bool operator<(const edge& right) const{
        return l<right.l;
    }
};

int main(){
    int n, t; cin>>n>>t;
    
    vector<vector<edge>> G(n);
    v2i minedge(n, vi(n, INF));
    for(int i=0; i<t; i++){
        int f, t, w; cin>>f>>t>>w;
        if(f==t) continue;
        minedge[f][t] = min(minedge[f][t], w);
        minedge[t][f] = min(minedge[t][f], w);
        G[f].push_back({t, w});
        G[t].push_back({f, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vb visit(n, false);
    vi d(n, INF);
    d[0] = 0; pq.push({0,0});
    v2i par(n);

    //最短経路を求めるが、最短経路が複数ある場合がある。
    while(!pq.empty()){
        auto [pc, pv] = pq.top();
        pq.pop();
        if(visit[pv]) continue;
        visit[pv] = true;

        for(auto v:G[pv]){
            auto [cv, cl] = v;
            if(d[cv] > d[pv]+cl){
                d[cv] = d[pv]+cl;
                pq.push({d[cv],cv});
                par[cv].clear();
                par[cv].push_back((pv));
            }
            else if(d[cv] == d[pv]+cl) par[cv].push_back(pv);
        }
    }
    // for(int i=0; i<n; i++) cout << d[i] << endl;

    int ans = 0; 
    queue<int> q; 
    vb visit2(n, false);
    q.push(n-1);
    while(!q.empty()){
        auto pv = q.front(); q.pop();
        if(visit2[pv]) continue;
        visit2[pv] = true;

        for(auto cv:par[pv]){
            // cout << pv << " " << cv << endl;
            ans += minedge[pv][cv];
            q.push(cv);
        }
    }
    cout << ans*2 << endl;
    return 0;
}