#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <numeric>
#include <map>
#include <cmath>
#define INF 1e9
#define vi vector<int>
#define vb vector<bool>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

struct edge{
    int to, cap, rev;
};

int dfs(int v, int t, int f, vb& visit, vector<vector<edge>>& G){
    if(v==t) return f;
    visit[v] = true;
    for(int i=0; i<G[v].size(); i++){
        edge& e = G[v][i];
        if(!visit[e.to] && e.cap>0){
            // cout << v << " " << e.to<<endl;
            int d = dfs(e.to, t, min(f, e.cap), visit, G);
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}


int main(){
    int n; cin>>n;
    vi iv(n);
    for(int i=0; i<n; i++) cin>>iv[i];
    sort(all(iv));
    map<int, int> v;
    for(int i=0; i<n; i++) v.insert(make_pair(iv[i], i));

    vector<vector<edge>> G(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int gcdij = __gcd(iv[i], iv[j]);
            if(gcdij>=2){
                G[i].push_back({j, gcdij, (int)G[j].size()});
                G[j].push_back({i, gcdij, (int)G[i].size()-1}); //追加後だから-1
            }
        }
    }
    int ans = 0;
    while(true){
        vb visit(n, false);
        int f = dfs(0, n-1, INF, visit, G);
        if(f==0) break;
        ans += f;        
    }
    cout << ans << endl;
    return 0;
}