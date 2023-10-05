#include <iostream>
#include <vector>
#include <string>
#define INF 1e9
#define v2i vector<vector<int>>
using namespace std;

//マス1からマスNにジャンプを繰り返すことで行きたい
//最初はマス1からマス2へ行く
//マスiには入場料c[i]がある
//前進するときは前のジャンプより1だけ長いジャンプをしなければならない
//後退するときは前のジャンプと同じ長さでなければいけない
//入場料の最小値を求める

int main(){
    int n; cin>>n;
    vector<int> c(n+1);
    //マスi(1~n)の入場料
    for(int i=1; i<=n; i++) cin>>c[i];

    int ans = INF;
    //dp[i][j]: ジャンプ幅iでjに来たときの最小コスト
    v2i dp(n+1, vector<int>(n+1, INF));
    //初期化．ジャンプ幅0で1に到達するコストは0である
    dp[0][1] = 0;
    for(int i=1; i<n; i++){
        //前進で到達できるマスの最大値(ジャンプ幅が1ずつ増えていくので，1+2+3+...)
        int maxj = min(n, 1+i*(i+1)/2);
        //ジャンプ幅iでjに前進する
        for(int j=1+i; j<=maxj; j++){
            //マス1,...,iから飛んでくる
            dp[i][j] = dp[i-1][j-i]+c[j];
            //nに到達したらコストの最小値を取る
            if(j==n) ans = min(ans, dp[i][j]);
        }
        //ジャンプ幅iでjに後退する
        for(int j=maxj-i; j>0; j--){
            dp[i][j] = min(dp[i][j+i]+c[j], dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}