#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define vi vector<int>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

struct SCC{
    int n, cmpnum;
    vector<vector<int>> G, rG;
    vector<int> vs, cmp;
    vector<bool> visit;

    SCC(int n, vector<vector<int>> G, vector<vector<int>> rG)
    : cmpnum(0), n(n), G(G), rG(rG), visit(n, false), cmp(n) { }

    void dfs(int v){
        visit[v] = true;
        for(auto nv:G[v]) if(!visit[nv]) dfs(nv);
        vs.push_back(v); 
        //番号を割り当てる
    }
    void rdfs(int v, int k){
        visit[v] = true;
        cmp[v] = k;
        for(auto nv:rG[v]) if(!visit[nv]) rdfs(nv, k);
    }
    int scc(){
        for(int i=0; i<n; i++) if(!visit[i]) {cmpnum++; dfs(i);}
        // for(auto v:vs) cout << v << " ";
        // cout << endl;
        fill(all(visit), false);
        int k = 0;
        for(int i=vs.size()-1; i>=0; i--) if(!visit[vs[i]]) rdfs(vs[i], k++);
        return k;
    }
};

int main(){
    int testcase; cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m; cin>>n>>m;

        v2i G(n), rG(n);
        for(int i=0; i<m; i++){
            int u, v; cin>>u>>v;
            u--; v--;
            G[u].push_back(v);
            rG[v].push_back(u);
        }
        SCC scc(n, G, rG);
        int k = scc.scc();

        if(k==1){
            cout << 0 << endl;
            continue;
        }
        vector<int> out(k,0), in(k,0);
        for(int i=0; i<n; i++){
            for(auto v:G[i]){
                if(scc.cmp[i]!=scc.cmp[v]){
                    out[scc.cmp[i]]++;
                    in[scc.cmp[v]]++;
                }
            }
        }
        int out0=0, in0=0;
        for(int i=0; i<k; i++){
            if(out[i]==0) out0++;
            if(in[i]==0) in0++;
        }
        cout << max(out0, in0) << endl;
    }
    return 0;
}