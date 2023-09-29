#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define all(x) x.begin(), x.end()
using namespace std;

int combination(int m, int n){
    vector<vector<int>> com(m+1, vector<int>(m+1));
    com[0][0] = 1;
    for(int i=1; i<=m; i++){
        com[i][0] = 1;
        for(int j=1; j<i; j++) com[i][j] = com[i-1][j-1] + com[i-1][j];
        com[i][i] = 1;
    }
    return com[m][n];
}

int main(){
    int game; cin>>game;
    for(int g=0; g<game; g++){
        int m; cin>>m;
        vector<int> tile(m);
        for(int i=0; i<m; i++) cin>>tile[i];
        int n, t; cin>>n>>t;

        if(n==0 && t==0) {cout << "Game " << g+1 << " -- " << 1 << " : " << 0 << endl; continue;}
        else if(n==0 && t>0) {cout << "Game " << g+1 << " -- " << 0 << " : " << 1 << endl; continue;}
        
        vector<vector<int>> l(n+1, vector<int>(t+1,0)), r(n+1, vector<int>(t+1,0));
        //半分全列挙
        for(int i=0; i<(1<<(m/2)); i++){
            int sum = 0, cnt = 0;
            for(int j=0; j<(m/2); j++){
                if(i&(1<<j)){
                    sum += tile[j]; 
                    cnt++;
                }
            }
            if(cnt>n || sum>t) continue;
            l[cnt][sum]++;
        }
        for(int i=0; i<(1<<(m-(m/2))); i++){
            int sum = 0, cnt = 0;
            for(int j=0; j<(m-(m/2)); j++){
                if(i&((1<<j))){
                    sum += tile[j+(m/2)];
                    cnt++;
                }
            }
            if(cnt>n || sum>t) continue;
            r[cnt][sum]++;
        }
        int win = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=t; j++){
                win += l[i][j]*r[n-i][t-j];
            }
        }
        cout << "Game " << g+1 << " -- " << win << " : " << combination(m,n)-win << endl;  
    }
    return 0;
}