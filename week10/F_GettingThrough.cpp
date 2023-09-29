#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define INF 1e9
#define all(x) x.begin(),x.end()
#define EPS 1e-8
using namespace std;

struct UnionFind
{
    int n;
    vector<int> par, rank, siz;
    UnionFind(int n) : n(n), par(n,-1), rank(n,0), siz(n,1) { }

    int root(int v){
        if(par[v]==-1) return v;
        else return par[v] = root(par[v]);
    }
 
    bool issame(int x, int y){
        return root(x)==root(y);
    }
 
    bool unite(int x, int y){
        int rx = root(x), ry = root(y);
        if (rx==ry) return false;
        if (rank[rx]<rank[ry]) swap(rx, ry);
        par[ry] = rx; 
        if (rank[rx]==rank[ry]) rank[rx]++;
        siz[rx] += siz[ry]; 
        return true;
    }
};

struct vec2{
    double x, y;
    bool operator<(const vec2& right) const {
        return y==right.y ? x<right.x : y<right.y;
    }
};

struct vertex{
    vec2 co; 
    double r;
};

double dist(vec2 st, vec2 ed){
    return sqrt((st.x-ed.x)*(st.x-ed.x) + (st.y-ed.y)*(st.y-ed.y));
}

int main(){
    int testcase; cin>>testcase;
    for(int t=0; t<testcase; t++){
        double w; int n; cin>>w>>n;
        vector<vertex> v(n);
        for(int i=0; i<n; i++) cin>>v[i].co.x>>v[i].co.y>>v[i].r;

        double left = -1.0, right = w;
        double mid = (left+right)/2;
        
        while(right-left>EPS){
            mid = (left+right)/2;

            // cout << left << " " << mid << " " << right << endl;

            UnionFind uf(n+2);
            //0は左の壁、1は右の壁とする
            for(int i=0; i<n; i++){
                if(v[i].co.x-v[i].r < mid) uf.unite(0, i+2);
                if(w-v[i].co.x-v[i].r < mid) uf.unite(1, i+2);
            }
            if(uf.issame(0,1)) {right = mid; continue;}
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(dist(v[i].co, v[j].co)-v[i].r-v[j].r < mid) uf.unite(i+2, j+2);
                }
            }
            if(uf.issame(0,1)) right = mid;
            else left = mid;
        }
        if(left<=0) cout << 0 << endl;
        else cout << fixed << setprecision(6) << left/2 << endl;
    }
    return 0;
}