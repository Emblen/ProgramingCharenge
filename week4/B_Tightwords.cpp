#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    int k, n; 
    while(cin>>k>>n){
        //使う数字が0まで，1までの場合と長さが1のときは100% tight wordsである
        if(k==0 || k==1 || n==1) {
            cout << fixed << setprecision(9) << 100.0 << endl;
            continue;
        }
        //0~kの数字が選ばれる確率
        double init = 1.0/(k+1);
        //dp[i][j]: i(0~n-1)番目の数字がjのとき，それがtight wordsになる確率
        vector<vector<double>> dp(n, vector<double>(k+1, init));
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                //i-1番目までで，jの差が1以下のものを取ってきて足す
                if(j==0) dp[i][j] = dp[i-1][j]+dp[i-1][j+1];
                else if(j==k) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
                //全部で(k+1)^nの選びかたがあるので逐一割る
                dp[i][j]/=(k+1);
            }
        }
        double ans = 0.0;
        for(int j=0; j<=k; j++) ans+=dp[n-1][j];
        //%表示にする
        cout << fixed << setprecision(9) << ans*100 << endl;
    }
    return 0;
}