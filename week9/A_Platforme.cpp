#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

struct Line{
    int y, st, ed;
    bool operator<(const Line& right) const{
        return y==right.y ? st<right.st : y<right.y;
    }
};

int main(){
    int n; cin>>n;
    vector<Line> lines(n);
    int maxx = -1;
    for(int i=0; i<n; i++){
        int a,b,c; cin>>a>>b>>c;
        lines[i] = {a, b, c};
        maxx = max(maxx, c);
    }
    sort(all(lines));
    vector<int> floor(maxx+1, 0);
    
    int ans = 0;
    for(int i=0; i<n; i++){
        auto [y, st, ed] = lines[i];
        ans += ((y-floor[st]) + (y-floor[ed-1]));
        for(int j=st; j<ed; j++) floor[j] = y;
    }
    cout << ans << endl;
    return 0;
}