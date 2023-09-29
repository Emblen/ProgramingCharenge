#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#define vi vector<int>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n==0) break;
        map<string, int> strnum;
        vector<vector<double>> d(n, vector<double>(n,0.0));
        //通貨の頂点番号をmapで管理
        for(int i=0; i<n; i++){
            string s; cin>>s;
            strnum.insert(make_pair(s,i));
            d[i][i] = 1.0;
        }
        //取引の辺情報
        int m; cin>>m;
        for(int i=0; i<m; i++){
            string from, to, rs; cin>>from>>to>>rs;
            int itr = rs.find(':');
            double r1 = stod(rs.substr(0,itr));
            double r2 = stod(rs.substr(itr+1));
            
            int fn = strnum[from], tn = strnum[to];
            d[fn][tn] = max(d[fn][tn],r2/r1);
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    d[i][j] = max(d[i][j], d[i][k]*d[k][j]);
                }
            }
        }
        bool ans = false;
        for(int i=0; i<n; i++){
            if(d[i][i]>1.0){
                cout << "Arbitrage" << endl;
                ans = true;
                break;
            }
        }
        if(!ans) cout << "Ok" << endl;
    }
    return 0;
}