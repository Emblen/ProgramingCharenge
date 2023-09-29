#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//dp[i] 長さi+1の増加部分列の中で、各列の右端の最小値
int LIS(int startval, vector<int> t){
    if(t.size()==0) return 0;
    vector<int> dp;
    dp.push_back(startval);
    for(int i=0; i!=t.size(); i++){
        int left = 0, right = dp.size()-1;
        int mid = (left + right)/2;
        while(right - left > 1){
            int mid = (left + right)/2;
            if(t[i] < dp[mid]) right = mid;
            else left = mid;
        }
        if(dp[right] < t[i]) dp.push_back(t[i]);
        else if(dp[left] < t[i]) dp[left+1] = t[i];
    }
    // for(auto v:dp) cout << v << " ";
    // cout << endl;
    return dp.size()-1;
}

int main(){
    int n; cin>>n;
    vector<int> t(n);
    for(int i=0; i<n; i++) cin>>t[i];

    int ans = 0;
    for(int i=0; i<n; i++){
        vector<int> tp, tm;
        for(int j=i+1; j<n; j++){
            if(t[i] < t[j]) tp.push_back(t[j]);
            else if(t[i] > t[j]) tm.push_back(-t[j]);
        }
        ans = max(ans, 1 + LIS(t[i],tp) + LIS(-t[i],tm));
    }
    cout << ans << endl;    
    return 0;
}