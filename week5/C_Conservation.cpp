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

int TopologicalSort(int n, int m, v2i G, vi deg, vi lab)
{
    vector<queue<int>> q(2);
    for(int i=0; i<n; i++) if(deg[i]==0) q[lab[i]-1].push(i);
    vector<int> ans(2,0);
    for(int i=0; i<2; i++){
        int clab = i;
        vector<queue<int>> tmpq = q;
        vector<int> tmpdeg = deg;
        while(!tmpq[0].empty() || !tmpq[1].empty()){
            while(!tmpq[clab].empty()){
                int pv = tmpq[clab].front();
                tmpq[clab].pop();
                
                for(auto cv:G[pv]){
                    tmpdeg[cv]--;
                    if(tmpdeg[cv]==0) tmpq[lab[cv]-1].push(cv);
                    //0ではない場合、探索していない頂点からの有向辺が存在する
                }
            }
            clab = 1-clab;
            ans[i]++;
        }
    }
    return min(ans[0]-1, ans[1]-1);
    
}

int main(){
    int testcase; cin>>testcase;
    for(int t=0; t<testcase; t++){
        int n, m; cin>>n>>m;
        v2i G(n);
        vi lab(n), deg(n);

        for(int i=0; i<n; i++) cin>>lab[i];
        for(int i=0; i<m; i++){
            int a,b; cin>>a>>b;
            a--; b--;
            deg[b]++;//入次数
            G[a].push_back(b);
        }
        cout << TopologicalSort(n, m, G, deg, lab) << endl;
    }
    return 0;
}