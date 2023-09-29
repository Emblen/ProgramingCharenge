#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        
        vector<int> t(n);
        vector<double> p(n), mp(n, 0);

        for(int i=0; i<n; i++){
            cin >> t[i] >> p[i];
            p[i] -= 0.08;
        }
        for(int i=1; i<n; i++){
            mp[i] = 0.08*(t[i]-t[i-1]-1);
            // cout << mp[i] << endl;
        }
        

        pair<int, int> mxt;
        double mx = -INF;
        for(int i=0; i<n; i++){
            double sum = 0.0;
            for(int j=i; j<n; j++){
                if(j==i) sum = p[j];
                else sum = sum + p[j] - mp[j];
                // cout << i << " " << j << " " << sum << endl;
                if(sum>mx){
                    mx = sum;
                    mxt = {t[i], t[j]};
                }
                else if(sum==mx){
                    if(t[j]-t[i] < mxt.second-mxt.first){
                        mxt = {t[i], t[j]};
                    }
                }
            }
        }
        if(mx <= 0) cout << "no profit" << endl;
        else cout << fixed << setprecision(2) << mx << " " << mxt.first << " " << mxt.second << endl;
    }
    return 0;
}