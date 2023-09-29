#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
#define v2i vector<vector<int>>
#define vi vector<int>
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    int y, x;
    bool operator<(const vec2& right) const {
        return y==right.y ? x<right.x : y<right.y;
    }
};

int main(){
    int n, m; cin>>n>>m;
    v2i a(n, vi(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            a[i][j] = c-'0';
        }
    }
    v2i cost(n, vi(m,INF));
    cost[0][0] = 0;
    priority_queue<pair<int, vec2>, vector<pair<int, vec2>>, greater<pair<int, vec2>>> pq;

    vector<vec2> dydx = {{0,1},{1,0},{-1,0},{0,-1}};
    pq.push({0,{0,0}});
    while(!pq.empty()){
        auto [pc, pv] = pq.top();
        auto [py, px] = pv;
        pq.pop();

        if(py==n-1 && px==m-1){
            cout << cost[py][px] << endl;
            return 0;
        }
        if(pc>cost[py][px]) continue;

        int k = a[py][px];
        for(auto d:dydx){
            int cy = d.y*k+py;
            int cx = d.x*k+px;
            if(cy<0 || cx<0 || cy>=n || cx>=m) continue;
            if(cost[cy][cx]>cost[py][px]+1){
                cost[cy][cx] = cost[py][px]+1;
                pq.push({cost[cy][cx],{cy,cx}});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}