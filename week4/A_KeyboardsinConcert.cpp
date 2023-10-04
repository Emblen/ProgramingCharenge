#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <bitset>
#define INF 1e9
#define vi vector<int>
#define vb vector<bool>
#define v2i vector<vector<int>>
#define v2b vector<vector<bool>>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    //n: 楽器数, m:音符数
    int n, m; cin>>n>>m;
    //楽器iで音符jを弾くことができるか
    v2b k(n, vb(m+1, false));
    for(int i=0; i<n; i++){
        int num; cin>>num;
        for(int j=0; j<num; j++){
            int knum; cin>>knum;
            k[i][knum] = true;
        }
    }
    int ans = 0;
    const int maxnum = 1000;
    //すべての楽器について，演奏できる状態に初期化して全ビットを1にする
    bitset<maxnum> can = bitset<maxnum>().set();
    for(int i=0; i<m; i++){
        //音符を入力
        int l; cin>>l;
        //lを演奏できるかどうか
        bitset<maxnum> local = bitset<maxnum>().set();
        for(int j=0; j<n; j++){
            //楽器jで音符lを演奏できない場合
            if(!k[j][l]){
                //演奏できない場合、そのキーボードのフラグを消す
                can[j] = 0;
                local[j] = 0;
            }
        }
        // cout << can << endl;
        //フラグが立っているキーボードが一つでもあれば交換は必要ない
        //フラグが全て消えた場合、lを演奏できるキーボードに変える．localはlを弾ける楽器にフラグが立っているため，これを採用．
        if(can.count() <= maxnum-n){
            can = local;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}