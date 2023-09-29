#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

constexpr double vel = 5.0;
constexpr double los = 2.0;

struct vec2{
    double x, y;
};
struct edge{
    double t;
    int v; 
};

double dist(vec2 st, vec2 ed){
    return sqrt((st.x-ed.x)*(st.x-ed.x) + (st.y-ed.y)*(st.y-ed.y));
}

int main(){
    vec2 s, g;
    cin >> s.x >> s.y >> g.x >> g.y;
    int n; cin>>n;
    vector<vec2> c(n+2);
    c[0] = s; c[n+1] = g;
    for(int i=1; i<=n; i++) cin>>c[i].x>>c[i].y;

    vector<vector<edge>> G(n+2);
    for(int i=0; i<n+2; i++){
        for(int j=i+1; j<n+2; j++){
            double time;
            if(i==0) time = dist(c[i], c[j])/vel;
            else time = min(los+fabs(dist(c[i], c[j])-50)/vel, dist(c[i], c[j])/vel);

            G[i].push_back({time, j});
            G[j].push_back({time, i});
        }
    }

    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    vector<bool> isconf(n+2, false);
    pq.push({0, 0});
    
    while(pq.top().second!=n+1){
        double total = pq.top().first;
        int pv = pq.top().second;
        pq.pop();
        isconf[pv] = true;

        for(auto nv:G[pv]) if(!isconf[nv.v]) pq.push({total+nv.t, nv.v});
    }

    cout << fixed << setprecision(6) << pq.top().first << endl;
    return 0;
}