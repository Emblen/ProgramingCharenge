#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
#define INF 1e9
#define EPS 1e-10
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    double x, y;
};

double dist(vec2 st, vec2 ed){
    return sqrt((st.x-ed.x)*(st.x-ed.x) + (st.y-ed.y)*(st.y-ed.y));
}

double cross(vec2 p, vec2 q, vec2 r){
    vec2 pq = {q.x-p.x, q.y-p.y};
    vec2 pr = {r.x-p.x, r.y-p.y};
    return pq.x*pr.y - pq.y*pr.x;
}

//Graham's Scanをして各頂点間の距離を求める
vec2 p;
bool angleCmp(vec2 a, vec2 b){
    if(fabs(cross(p, a, b))<EPS) return dist(p, a) < dist(p, b);

    double pa = atan2((a.y-p.y), (a.x-p.x));
    double pb = atan2((b.y-p.y), (b.x-p.x));    
    return pa < pb;
}

vector<vec2> ConvexHull(vector<vec2> v){
    int n = (int)v.size();
    if(n<=3){
        if((v[0].x!=v[n-1].x)||(v[0].y!=v[n-1].y)){
            v.push_back(v[0]);
            return v;
        }
    }
    int p0 = 0;
    for(int i=1; i<n; i++){
        if((v[i].y < v[p0].y) || (v[i].y==v[p0].y && v[i].x>v[p0].x)) p0 = i;
    }
    vec2 tmp = v[0]; v[0] = v[p0]; v[p0] = tmp;
    p = v[0];
    sort(++v.begin(), v.end(), angleCmp);

    vector<vec2> s = {v[n-1], v[0], v[1]};
    int i = 2;
    while(i<n){
        int j = (int)s.size()-1;
        //反時計回りでは外積が正値
        if(cross(s[j-1], s[j], v[i]) > 0) s.push_back(v[i++]);
        else s.pop_back();
    }
    return s;
}

int main(){
    int n; cin>>n;
    vector<vec2> v(n);
    for(int i=0; i<n; i++) cin>>v[i].x>>v[i].y;
    
    // ofstream input("original.txt");
    // for(auto p:v) input << p.x << " " << p.y << endl;

    vector<vec2> ch = ConvexHull(v);

    // cout << "=======================" << endl;
    // ofstream output("data.txt");
    // for(auto v:ch) output << v.x << " " << v.y << endl;

    int m = (int)ch.size();
    double ans = 0.0;
    for(int i=0; i<m-2; i++){
        for(int j=i+1; j<m-1; j++){
            double d = dist(ch[i], ch[j]);
            ans = max(ans, d);
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}