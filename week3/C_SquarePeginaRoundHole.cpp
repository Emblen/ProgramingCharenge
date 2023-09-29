#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int n, m, k; cin>>n>>m>>k;
    vector<int> plot(n), house(m+k);
    for(int i=0; i<n; i++) cin>>plot[i];
    for(int i=0; i<m; i++) cin>>house[i];
    for(int i=0; i<k; i++){
        cin>>house[i+m];
        house[i+m]/=sqrt(2);
    }
    sort(all(plot), greater<int>());
    sort(all(house), greater<int>());

    int ans=0, j=0;
    for(int i=0; i<n; i++){
        while(j<m+k && plot[i]<=house[j]) j++;
        if(j>=m+k) break;
        ans++; j++;
    }
    cout << ans << endl;
    return 0;
}