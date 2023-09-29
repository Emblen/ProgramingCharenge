#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> p(n, vector<int>(m));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>p[i][j];

    vector<vector<int>> st(n, vector<int>(m+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i!=n-1) st[i+1][j] = max(st[i+1][j], st[i][j]+p[i][j]);
            if(j==m-1) continue;
            st[i][j+1] = max(st[i][j+1], st[i][j]+p[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        st[i][m] = st[i][m-1]+p[i][m-1];
        cout << st[i][m] << " ";
    }
    cout << endl;
    return 0;
}