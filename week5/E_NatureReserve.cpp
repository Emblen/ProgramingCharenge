#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define v2i vector<vector<int>>
#define all(x) x.begin(),x.end()
using namespace std;

struct edge{
    int from, to;
    long long weight;

    bool operator<(const edge& right) const{
        return weight < right.weight;
    }
};

struct UnionFind
{
    int n;
    vector<int> par, rank, siz, edgenum;
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
    int dataset; cin>>dataset;

    for(int d=0; d<dataset; d++){
        int n, m, l, s;
        cin >> n >> m >> l >> s;
        vector<int> inits(s);
        for(int i=0; i<s; i++){
            int num; cin >> num;
            inits[i] = num-1;
        }
        UnionFind uf(n);
        if(s!=1) for(int i=1; i<s; i++) uf.unite(inits[0], inits[i]);

        vector<edge> stations(m);
        for(int i=0; i<m; i++){
            int a, b;
            long long w;
            cin >> a >> b >> w;
            a--; b--;
            stations[i] = {a, b, w+(long long)l};
        }
        sort(all(stations));

        long long ans = 0;
        for(int i=0; i<m; i++){
            auto [a, b, w] = stations[i];

            if(uf.issame(a, b)) continue;

            uf.unite(a, b);
            ans += w;
        }
        cout << ans << endl;
    }   
    return 0;
}