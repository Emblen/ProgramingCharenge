#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//i=0からh-1まで　下からiより大　かつ　上からi+1より小　の壁の個数の和の最小

int main(){
    int n, h; cin>>n>>h;
    vector<int> cwalls(h+1, 0), gwalls(h+1, 0);
    for(int i=0; i<n; i++){
        int w; cin>>w;
        if(i%2) gwalls[w]++;
        else cwalls[h+1-w]++;
    }   
    for(int i=h-1; i>=0; i--) gwalls[i]+=gwalls[i+1];
    for(int i=1; i<=h; i++) cwalls[i]+=cwalls[i-1];
    // for(int i=1; i<=h; i++) cout << cwalls[i] << " ";
    // cout << endl;
    // for(int i=1; i<=h; i++) cout << gwalls[i] << " ";

    int cnt=0, minwalls=1e9;
    for(int i=1; i<=h; i++){
        int sum = cwalls[i]+gwalls[i];
        if(sum<minwalls){
            minwalls = sum;
            cnt = 1;
        }
        else if(sum==minwalls) cnt++;
    }
    cout << minwalls << " " << cnt << endl;
    return 0;
}