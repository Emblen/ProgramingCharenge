#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    int y, x;
};

int main(){
    int n, m; cin>>n>>m;
    vector<string> cinmap(n);
    for(int i=0; i<n; i++) cin>>cinmap[i];

    vector<vector<int>> map(n+2, vector<int>(m+2,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) map[i][j] = cinmap[i-1][j-1]-'0';
    }

    vector<vector<int>> newmap(n+2, vector<int>(m+2,1));
    vector<vector<bool>> visit(n+2, vector<bool>(m+2, false));

    queue<vec2> q;
    vector<vec2> dydx = {{1,0},{0,1},{-1,0},{0,-1}};
    q.push({0,0});
            
    while(!q.empty()){
        vec2 pv = q.front(); q.pop();
        if(visit[pv.y][pv.x]) continue;
        newmap[pv.y][pv.x] = 0;
        visit[pv.y][pv.x] = true;

        for(auto d:dydx){
            int nvy = pv.y+d.y;
            int nvx = pv.x+d.x;
            if(nvy<0 || nvy>=n+2 || nvx<0 || nvx>=m+2 || visit[nvy][nvx] || map[nvy][nvx]) continue;
            q.push({nvy, nvx});
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++) cout << newmap[i][j] << " ";
    //     cout << endl;
    // }
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(!newmap[i][j]) continue;
            
            for(auto d:dydx){
                int nvy = i+d.y;
                int nvx = j+d.x;
                if(!newmap[nvy][nvx]) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}