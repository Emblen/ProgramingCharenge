#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    int y, x;
};

int main(){
    int w, h; cin>>w>>h;
    vector<vector<char>> map(h, vector<char>(w));
    vec2 start;
    queue<vec2> q;
    vector<vec2> dydx = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<bool>> visit(h, vector<bool>(w, false));

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> map[i][j];
            if(map[i][j]=='P') q.push({i, j});
        }
    }

    int ans = 0;
    while(!q.empty()){
        vec2 now = q.front();
        q.pop();
        if(visit[now.y][now.x]) continue;
        if(map[now.y][now.x]=='G') ans++;
        map[now.y][now.x] = 'P';
        visit[now.y][now.x] = true;

        // for(int i=0; i<h; i++){
        //     for(int j=0; j<w; j++) cout << map[i][j];
        //     cout << endl;
        // }
        // map[now.y][now.x] = '.';
        // cout << endl;

        bool danger = false;
        for(auto nv: dydx){
            int ny = now.y+nv.y;
            int nx = now.x+nv.x;
            if(visit[ny][nx]) continue;
            if(map[ny][nx]=='T'){
                danger = true;
                break;
            }
        }
        if(danger) continue;

        for(auto nv:dydx){
            int ny = now.y+nv.y;
            int nx = now.x+nv.x;
            if(visit[ny][nx]) continue;

            char nc = map[ny][nx];
            if(nc=='#'){
                visit[ny][nx] = true;
                continue;
            }
            else if(nc=='T') continue;

            q.push({ny,nx});
        }
    }
    cout << ans << endl;
    return 0;
}