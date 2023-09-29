#include <iostream>
#include <vector>
using namespace std;

constexpr int mx = 80;

int main(){
    int n; cin>>n;
    vector<int> cube(mx+1);
    for(int i=1; i<=mx; i++) cube[i] = i*i*i;
    
    vector<int> cnt(n+1, 0);
    for(int i=1; i<=mx; i++){
        for(int j=i; j<=mx; j++){
            int sum = cube[i]+cube[j];
            if(sum>n) break;
            cnt[sum]++;
        }
    }
    for(int i=n; i>=1; i--){
        if(cnt[i]>=2) {cout << i << endl; return 0;}
    }
    cout << "none" << endl;
    return 0;
}