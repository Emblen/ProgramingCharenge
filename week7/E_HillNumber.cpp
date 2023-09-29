#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define INF 1e9
#define vi vector<int>
#define v2i vector<vector<int>>
#define v3i vector<vector<vector<int>>>
#define vll vector<long long>
#define v2ll vector<vector<long long>>
#define v3ll vector<vector<vector<long long>>>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.length();

    //桁DP  dp[smaller][prenum][isdown]
    
    v3ll pre(2, v2ll(10, vll(2, 0)));
    pre[0][0][0] = 1;
    int psi = 0;
    for(int i=1; i<=n; i++){
        v3ll now(2, v2ll(10, vll(2, 0)));
        int si = s[i-1]-'0';
        
        if(psi<si){
            if(pre[0][psi][1]){//下降しているときに上昇はできない
                cout << -1 << endl;
                return 0;
            }
            now[0][si][0] = pre[0][psi][0]; 
            now[0][si][1] = pre[0][psi][1];
              
            for(int k=0; k<psi; k++) now[1][k][1] += pre[0][psi][0]; //psiより小さければ下降
            for(int k=psi; k<si; k++) now[1][k][0] += pre[0][psi][0]; //psi以上でsiより小さければ上昇
        }

        else if(si==psi){
            now[0][si][0] = pre[0][psi][0]; 
            now[0][si][1] = pre[0][psi][1];
            for(int k=0; k<si; k++) now[1][k][1] = pre[0][psi][0] + pre[0][psi][1]; //新たにsmallerとなり、下降。
        }
        else{
            now[0][si][1] = pre[0][psi][0] + pre[0][psi][1];
            for(int k=0; k<si; k++) now[1][k][1] = pre[0][psi][0] + pre[0][psi][1]; //新たにsmallerとなり、下降。
        }

        //その他
        for(int l=0; l<10; l++){
            for(int k=0; k<10; k++){
                if(l==k){
                    //上昇、下降のステータスを保持
                    now[1][k][0] += pre[1][l][0];
                    now[1][k][1] += pre[1][l][1];
                }
                else if(l<k) now[1][k][0] += pre[1][l][0]; // 上昇を続ける
                else now[1][k][1] += (pre[1][l][0] + pre[1][l][1]);  //上昇から下降、下降からさらに下降
            }
        }
        pre = now;
        psi = si;
        // cout << i << endl;
        // for(int j=0; j<10; j++){
        //     cout << j <<": ";
        //     cout << now[0][j][0] <<" " <<now[0][j][1] <<" "<< now[1][j][0] <<" "<< now[1][j][1]<<endl;
        // }
    }
    long long ans = 0;
    for(int k=0; k<10; k++) ans += (pre[1][k][0] + pre[1][k][1]);
    cout << ans << endl; //元の数で+1、0で-1
    return 0;
}