#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

struct vec2{
    int x, y;
};

bool cmp(vec2 a, vec2 b){
    double ga = (double)a.y/(double)a.x;
    double gb = (double)b.y/(double)b.x;
    return ga < gb;
}

int main(){
    int n; cin>>n;
    vector<vec2> coprime;
    bool flag = false;
    for(int i=2; ; i++){
        for(int j=1; j<i; j++){
            if(__gcd(j, i-j)==1){
                coprime.push_back({j, i-j});
                if((int)coprime.size()==(n/4+1)) {flag = true; break;}
            }
        }
        if(flag) break;
    }
    sort(all(coprime), cmp);
    int siz = (int)coprime.size();

    // vector<vec2> polygon;
    vec2 now = {(int)2e7, 0};
    // polygon.push_back(now);
    cout << now.x << " " << now.y << endl;
    int cnt = 1;

    
    for(int i=0; i<siz; i++){
        // if((int)polygon.size()==n) break;
        if(cnt==n) break;
        auto [dx, dy] = coprime[i];
        now.x += dx; now.y += dy;
        cout << now.x << " " << now.y << endl;
        cnt++;
        // polygon.push_back(now);
    }
    for(int i=siz-1; i>=0; i--){
        if(cnt==n) break;
        // if((int)polygon.size()==n) break;
        auto [dx, dy] = coprime[i];
        now.x -= dx; now.y += dy;
        cout << now.x << " " << now.y << endl;
        // polygon.push_back(now);
        cnt++;
    }
    for(int i=0; i<siz; i++){
        if(cnt==n) break;
        // if((int)polygon.size()==n) break;
        auto [dx, dy] = coprime[i];
        now.x -= dx; now.y -= dy;
        cout << now.x << " " << now.y << endl;
        cnt++;
        // polygon.push_back(now);
    }
    for(int i=siz-1; i>=0; i--){
        if(cnt==n) break;
        // if((int)polygon.size()==n) break;
        auto [dx, dy] = coprime[i];
        now.x += dx; now.y -= dy;
        cout << now.x << " " << now.y << endl;
        cnt++;
        // polygon.push_back(now);
    }
    // for(auto v:polygon) cout << v.x << " " << v.y << endl;
    return 0;
}