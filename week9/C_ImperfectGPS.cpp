#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct vec2{
    double x, y;
};
struct Data{
    vec2 v; int time;
};

double dist(vec2 st, vec2 ed){
    return sqrt((st.x-ed.x)*(st.x-ed.x) + (st.y-ed.y)*(st.y-ed.y));
}

int main(){
    int n, t; cin>>n>>t;
    vector<Data> data(n);
    for(int i=0; i<n; i++) cin>>data[i].v.x>>data[i].v.y>>data[i].time;
    int end = data[n-1].time;
    
    vector<vec2> f(end+1);
    f[0] = data[0].v;
    double px = data[0].v.x, py = data[0].v.y; int pt = 0;
    double totaldist = 0.0;
    for(int i=1; i<n; i++){
        totaldist += dist(data[i-1].v, data[i].v);

        double nx = data[i].v.x, ny = data[i].v.y;
        int nt = data[i].time;
        
        double dx = (nx-px)/(double)(nt-pt), dy = (ny-py)/(double)(nt-pt);
        for(int j=pt+1; j<nt; j++){
            f[j].x = f[pt].x + dx*(double)(j-pt);
            f[j].y = f[pt].y + dy*(double)(j-pt);
            // cout << j << " " << f[j].x << " "<<f[j].y << endl;
        }
        f[nt] = {nx, ny};
        px = nx; py = ny, pt = nt;
    }
    // for(int i=0; i<=end; i++){
    //     cout << f[i].x << " " << f[i].y << endl;
    // }
    double GPSdist = 0.0;
    int i = 0;
    while(i+t<=end){
        i += t;
        GPSdist += dist(f[i-t], f[i]);
    }
    GPSdist += dist(f[i], f[end]);
    cout << fixed << setprecision(14) << (totaldist-GPSdist)*100/totaldist << endl;
    return 0;
}