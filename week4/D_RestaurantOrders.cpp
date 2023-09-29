#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define v2i vector<vector<int>> 
#define v3i vector<vector<vector<int>>>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

//個数制限なしナップサックDP
//dp[i][j]: i番目までのmenuから任意に何個ずつか取って合計をjにする方法が何通り存在するか


int main(){
    int n; cin>>n;
    vector<int> menu(n);
    for(int i=0; i<n; i++) cin>>menu[i];
    int m; cin>>m;

    vector<int> query(m);
    int max = 0;
    for(int i=0; i<m; i++){
        cin>>query[i];
        if(query[i]>max) max = query[i];
    }

    v2i dp(2, vector<int>(max+1,0));
    v3i order(2, v2i(max+1, vector<int>(n+1,0)));

    dp[1][0] = 1;
    for(int i=1; i<=n; i++){
        dp[0] = dp[1];
        order[0] = order[1];

        for(int j=0; j<=max; j++){
            dp[1][j] = dp[0][j];
            order[1][j] = order[0][j];

            if(j-menu[i-1]>=0 && dp[1][j-menu[i-1]]>0){
                dp[1][j] += dp[1][j-menu[i-1]];
                if(dp[1][j]<2){
                    order[1][j] = order[1][j-menu[i-1]];
                    order[1][j][i]++;
                }
            }
        }
    }
    for(int i=0; i<m; i++){
        int cost = query[i];
        if(dp[1][cost]==1){
            for(int i=1; i<=n; i++){
                for(int j=0; j<order[1][cost][i]; j++) cout << i << " ";
            }
        }
        else if(dp[1][cost]==0) cout << "Impossible";
        else cout << "Ambiguous";
        cout << endl;
    }
    return 0;
}