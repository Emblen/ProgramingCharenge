#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <cmath>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    vector<bool> num(n+1, true);
    int cnt = 0;
    for(int i=2; i<=n; i++){
        if(!num[i]) continue;
        
        cnt++;
        num[i] = false;
        if(cnt==k) {cout << i << endl; return 0;}

        if(i>=sqrt(n)) continue;
        for(int j=i*i; j<=n; j+=i){
            if(num[j]) {cnt++; num[j] = false;}
            if(cnt==k) {cout << j << endl; return 0;}
        }
    }
    return 0;
}