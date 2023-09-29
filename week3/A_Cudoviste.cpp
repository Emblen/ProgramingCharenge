#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int  r, c; cin>>r>>c;
    vector<string> parking(r);
    for(int i=0; i<r; i++) cin>>parking[i];

    vector<pair<int,int>> dydx = {{0,0},{0,1},{1,1},{1,0}};
    vector<int> ans(5, 0);
    for(int i=0; i<=r-2; i++){
        for(int j=0; j<=c-2; j++){
            bool isok = true;
            int cnt = 0;
            for(auto [nvy,nvx]:dydx){
                char tmpc = parking[i+nvy][j+nvx];
                if(tmpc=='#'){
                    isok = false;
                    break;
                }
                else if(tmpc=='X') cnt++;
            }
            if(isok) ans[cnt]++;
        }
    }
    for(auto v:ans) cout << v << " ";
    cout << endl;
    return 0;
}