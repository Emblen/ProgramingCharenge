
Week10: Remix
Role: Student
Submission 11223791
Edit and resubmit
DATE	PROBLEM	JUDGEMENT	RUNTIME	LANGUAGE
2023-06-26 15:57:49	Week10: Remix / Bee Problem	
Accepted
0.28 s	C++
Files submitted
beeproblem.cpp
 Download file
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
    int h, r, c; cin>>h>>r>>c;
    

    int n = r*c;
    vector<int> num(n);
    vector<vector<int>> G(n);
    vector<vec2> od = {{0,1},{1,0},{1,1}}, ed = {{0,1},{1,-1},{1,0}};

    int cnt = 0;
    while(cnt<n){
        char c; cin>>c;
        if(c=='#') num[cnt++] = 1;
        else if(c=='.') num[cnt++] = 0;
    }
    if(h==0) {cout << 0 << endl; return 0;}
    else if(h==1) {cout << 1 << endl; return 0;}
    
    for(int i=0; i<r; i++){
        vector<vec2> d = (i%2 ? od : ed);
        for(int j=0; j<c; j++){
            if(num[c*i+j]) continue;
            for(auto v:d){
                int ny = i+v.y, nx = j+v.x;
                int a = c*i+j, b = c*ny+nx;
                if(nx<0 || nx>= c || ny<0 || ny>=r || num[b]) continue;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
    }

    vector<int> sizvec;
    vector<bool> visit(n, false);
    for(int i=0; i<n; i++){
        if(visit[i] || num[i]) continue;
        queue<int> q; q.push(i);
        int cnt = 0;
        
        while(!q.empty()){
            int pv = q.front(); q.pop();
            if(visit[pv]) continue;
            visit[pv] = true;
            cnt++;
            for(auto v:G[pv]){
                if(visit[v] || num[v]) continue;
                q.push(v);
            }
        }
        sizvec.push_back(cnt);
    }
    sort(all(sizvec), greater<int>());
    for(int i=0; i<(int)sizvec.size(); i++){
        h -= sizvec[i];
        if(h<=0) {cout << i+1 << endl; return 0;}
    }

    return 0;
}