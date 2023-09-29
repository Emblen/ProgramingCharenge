#include <iostream>
#include <vector>
#include <string>
#define INF 1e9
#define v2i vector<vector<int>>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> c(n+1);
    for(int i=1; i<=n; i++) cin>>c[i];

    int ans = INF;
    //dp[i][j]: ジャンプ幅iでjに来たときの最小コスト
    v2i dp(n+1, vector<int>(n+1, INF));
    dp[0][1] = 0;
    for(int i=1; i<n; i++){
        int maxj = min(n, 1+i*(i+1)/2);

        for(int j=1+i; j<=maxj; j++){
            dp[i][j] = dp[i-1][j-i]+c[j];
            if(j==n) ans = min(ans, dp[i][j]);
        }

        for(int j=maxj-i; j>=0; j--){
            dp[i][j] = min(dp[i][j+i]+c[j], dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}