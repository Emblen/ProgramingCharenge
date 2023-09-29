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

struct vec2{
    int y, x;
    bool operator<(const vec2 right) const {
        return y==right.y ? x<right.x : y<right.y;
    }
};

const string cmp = "ICPCASIASG";
const vector<vec2> dydx = {{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};

struct Solver{
    int n; 
    vector<vector<char>> s;
    Solver(int n, vector<vector<char>> s)
    : n(n), s(s) { }

    bool solve(vec2 start){
        priority_queue<pair<int, vec2>> pq;
        pq.push({0, start});
        while(!pq.empty()){
            auto [k, pv] = pq.top();
            // cout << k << " (" << pv.y << "," <<pv.x << ")" << endl;
            if(k==cmp.length()-1) return true;
            pq.pop();
            
            for(auto d:dydx){
                int ny = pv.y+d.y;
                int nx = pv.x+d.x;
                if(ny<0 || ny>=n || nx<0 || nx>=n || s[ny][nx]!=cmp[k+1]) continue;
                pq.push({k+1, {ny,nx}});
            }
        }
        return false;
    }
};

int main(){
    int n; cin>>n;
    vector<vector<char>> s(n, vector<char>(n));
    vector<vec2> start;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>s[i][j];
            if(s[i][j]=='I') start.push_back({i,j});
        }
    }
    Solver solver(n, s);
    for(auto st:start) if(solver.solve(st)) {cout << "YES" << endl; return 0;}
    cout << "NO" << endl;
    return 0;
}