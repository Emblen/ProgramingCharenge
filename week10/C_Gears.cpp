#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

struct vec2{
    int x, y;
};
struct gear{
    vec2 p; int r;
};
int connect(gear g1, gear g2){
    return (g1.p.x-g2.p.x)*(g1.p.x-g2.p.x)+(g1.p.y-g2.p.y)*(g1.p.y-g2.p.y) == (g1.r+g2.r)*(g1.r+g2.r);
}

struct Solver{
    int n, length, ans;
    vector<gear> gears;
    vector<vector<int>> G;
    vector<bool> visit;
    vector<int> pl;
    Solver(int n, vector<gear> gears, vector<vector<int>> G)
    : n(n), gears(gears), G(G), visit(n, false), pl(n, -1), length(0), ans(0) { }

    bool dfs(int nv, int tv, int l){
        if(pl[nv]<0) pl[nv] = l;
        else if(pl[nv]%2 != l%2) return false;

        if(nv==tv) {ans = l; return true;}
        visit[nv] = true;
        for(auto v:G[nv]){
            if(visit[v]) continue;
            if(dfs(v, tv, l+1)==false) return false;
        }
        visit[nv] = false;
        return true;
    }
    
    void solve(){
        if(dfs(0, n-1, 1)){
            if(ans==0) cout << 0 << endl;
            else{
                int sg = gears[0].r, tg = gears[n-1].r;
                int div = __gcd(sg, tg);
                sg/=div, tg/=div;
                if(ans%2==0) sg*=-1;
                cout << tg << " " << sg << endl;
                //速度の比
            }
        }
        else cout << -1 << endl;
        return;
    }
};

int main(){
    int n; cin>>n;
    vector<gear> gears(n);
    vector<vector<int>> G(n);
    for(int i=0; i<n; i++){
        cin>>gears[i].p.x>>gears[i].p.y>>gears[i].r;
        for(int j=0; j<i; j++){
            if(connect(gears[i], gears[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    Solver solver(n, gears, G);
    solver.solve();

    return 0;
}