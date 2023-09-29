#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define all(x) x.begin(),x.end()
using namespace std;

struct UnionFind
{
    int n;
    vector<int> par, rank, siz;
    UnionFind(int n) : n(n), par(n,-1), rank(n,0), siz(n,1) { }

    int root(int v)
    {
        if(par[v]==-1) return v;
        else return par[v] = root(par[v]);
    }
 
    bool issame(int x, int y)
    {
        return root(x)==root(y);
    }
 
    bool unite(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx==ry) return false;
        if (rank[rx]<rank[ry]) swap(rx, ry);
        par[ry] = rx; 
        if (rank[rx]==rank[ry]) rank[rx]++;
        siz[rx] += siz[ry]; 
        return true;
    }
};

int main(){
    int n, m; cin>>n>>m;

    UnionFind uf(n);
    vector<vector<int>> G(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        uf.unite(a, b);
    }
    int root0 = uf.root(0);
    int cnt = 0;
    for(int i=1; i<n; i++){
        if(uf.root(i)!=root0){
            cout << i+1 << endl;
            cnt++;
        }
    }
    if(cnt==0) cout << "Connected" << endl;

    return 0;
}