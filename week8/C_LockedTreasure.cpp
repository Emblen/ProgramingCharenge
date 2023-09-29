#include <iostream>
#include <vector>
using namespace std;

long long combination(int m, int n){
    vector<vector<int>> com(m+1, vector<int>(m+1));
    com[0][0] = 1;
    for(int i=1; i<=m; i++){
        com[i][0] = 1;
        for(int j=1; j<=m; j++) com[i][j] = com[i-1][j-1] + com[i-1][j];
    }
    return com[m][n];
}

int main(){
    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n, m; cin>>n>>m;
        cout << combination(n, m-1) << endl;
    }
    return 0;
}