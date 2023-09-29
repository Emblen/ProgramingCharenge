#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

struct edge{
    int to, d;
};

int main(){
    int n, m, a, k; 
    while(cin>>n>>m>>a>>k){
        if(n==0) break;

        vector<vector<edge>> G(n);
        vector<int> ndist(n, k);

        for(int i=0; i<m; i++){
            int f, t, dist; cin>>f>>t>>dist;
            if(dist>=k) continue;
            f--; t--;
            G[f].push_back({t, dist});
            G[t].push_back({f, dist});
        }
        set<int> notsafe;

        for(int i=0; i<a; i++){
            int root; cin>>root;
            root--;
            if((int)notsafe.size()==n) {cout << 0 << endl; continue;}

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<bool> isconf(n, false);

            pq.push({0, root});
            while(!pq.empty()){
                int dist = pq.top().first;
                int pv = pq.top().second;
                pq.pop();
                if(isconf[pv]) continue;

                notsafe.insert(pv);
                ndist[pv] = dist;
                isconf[pv] = true;
                for(auto nv:G[pv]){
                    if(isconf[nv.to] || dist+nv.d>=ndist[nv.to]) continue;
                    pq.push({dist+nv.d, nv.to});
                }
            }
            cout << n-(int)notsafe.size() << endl;
        }
        cout << endl;
    }
    return 0;
}