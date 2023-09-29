#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
#define vi vector<int>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    int y, x;

    bool operator<(const vec2& right) const {
        return y==right.y ? x<right.x : y<right.y;
    }
};

int main(){
    int r, c; cin>>r>>c;
    v2i mud(r, vi(c));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) cin>>mud[i][j];
    }
    priority_queue<pair<int, vec2>, vector<pair<int, vec2>>, greater<pair<int, vec2>>> pq;

    v2i depth(r, vi(c, INF));
    for(int i=0; i<r; i++){
        pq.push({mud[i][0], {i,0}});
        depth[i][0] = mud[i][0];
    }
    vec2 ans;
    vector<vec2> dydx = {{0,1},{0,-1},{1,0},{-1,0}};
    while(!pq.empty()){
        auto [pv, pc] = pq.top();
        auto [py, px] = pc;
        pq.pop();
        if(px==c-1){
            ans.y = py; ans.x = px;
            break;
        }

        for(auto d:dydx){
            int cy = py+d.y;
            int cx = px+d.x;
            if(cy<0 || cx<0 || cy>=r || cx>=c) continue;
            if(depth[cy][cx] > max(depth[py][px], mud[cy][cx])){
                depth[cy][cx] = max(depth[py][px], mud[cy][cx]);
                pq.push({depth[cy][cx], {cy, cx}});
            }
        }

    }
    cout << depth[ans.y][ans.x] << endl;
    return 0;
}