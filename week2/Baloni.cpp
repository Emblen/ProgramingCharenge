#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    int ans = 0;
    vector<int> snum(n+10, 0);
    for(int i=0; i<n; i++){
        int h; cin>>h;
        if(snum[h]) snum[h]--;
        else ans++;
        snum[h-1]++;
    }
    cout << ans << endl;
}  