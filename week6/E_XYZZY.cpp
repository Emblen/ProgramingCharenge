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
using ll = long long;
constexpr int se = 100;

void BellmannFord(vector<vector<pair<int, ll>>> e, int s, vector<ll>& dist, vb& iscycle){
    dist[s] = 0;
    for(int i=0; i<(int)e.size()-1; i++){
        for(int j=0; j<(int)e.size(); j++){
            if(dist[j]<INF){
                for(auto &a:e[j]) if(dist[j]+a.second < 0) dist[a.first] = min(dist[a.first], dist[j]+a.second);
            }
        }
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int j=0; j<(int)e.size(); j++){
            if(dist[j]==INF) continue;
            for(auto &a:e[j]){
                if(dist[a.first] > dist[j]+a.second && !iscycle[a.first] && (dist[j]+a.second < 0)){
                    dist[a.first] = -INF;
                    flag = true;
                    iscycle[a.first] = true;
                }
            }
        }
    }
}

int main(){
    int n;
    while(cin>>n && n!=-1){
        vector<vector<pair<int, ll>>> e(n+1);
        vector<ll> w(n+1);

        for (int i=1; i<=n; i++){
            cin >> w[i];
            int m; cin>>m;
            for (int j=0; j<m; j++){
                int k; cin>>k;
                e[i].push_back({k, 0});
            }
        }
        e[0].push_back({1, -w[1]-se});
        for(int i=1; i<=n; i++){
            for(int j=0; j<(int)e[i].size(); j++){
                e[i][j].second = -w[e[i][j].first];//各頂点への辺の重みを求める
            }
        }
        vector<ll> dist(n+1, INF);
        vb iscycle(n+1, false);
        BellmannFord(e, 0, dist, iscycle);

        if(iscycle[n] || dist[n]<0) cout << "winnable" << endl;
        else cout << "hopeless" << endl;
    }
    return 0;
}