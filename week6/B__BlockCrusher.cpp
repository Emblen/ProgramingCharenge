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
    int h, w; 
    while(cin>>h>>w){
        if(h==0 && w==0) break;

        v2i a(h, vi(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                char c; cin>>c;
                a[i][j] = c-'0';
            }
        }
        v2i cost(h, vi(w,INF));
        vector<vector<vec2>> par(h, vector<vec2>(w));
        priority_queue<pair<int, vec2>, vector<pair<int, vec2>>, greater<pair<int, vec2>>> pq;
        for(int i=0; i<w; i++){
            pq.push({a[0][i],{0,i}});
            cost[0][i] = a[0][i];
            par[0][i] = {0,i};
        }

        vector<vec2> dydx = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        int gy, gx;
        while(!pq.empty()){
            auto [pc, pv] = pq.top();
            auto [py, px] = pv;
            pq.pop();

            if(py==h-1){
                gy = py; gx = px;
                break;
            }
            if(pc>cost[py][px]) continue;

            for(auto d:dydx){
                int cy = d.y+py;
                int cx = d.x+px;
                if(cy<0 || cx<0 || cy>=h || cx>=w) continue;
                if(cost[cy][cx]>cost[py][px]+a[cy][cx]){
                    cost[cy][cx] = cost[py][px]+a[cy][cx];
                    pq.push({cost[cy][cx],{cy,cx}});
                    par[cy][cx] = {py,px};
                    // cout << pc << " "<<py<<" "<<px<< ":"<<cost[cy][cx] << " "<<cy << " "<<cx<<endl;
                }
            }
        }
        vec2 path = {gy, gx};
        while(path.y!=0){
            a[path.y][path.x] = 0;
            path = par[path.y][path.x];
        }
        a[path.y][path.x] = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(a[i][j]==0) cout << " ";
                else cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}