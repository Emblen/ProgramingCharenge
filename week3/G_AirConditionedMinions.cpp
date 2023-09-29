#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

struct Tempreture{
    int l, u;

    bool operator<(const Tempreture& right) const {
        return u==right.u ? l<right.l : u<right.u;
    }
};

int main(){
    int n; cin>>n;
    vector<Tempreture> temp(n);
    for(int i=0; i<n; i++) cin>>temp[i].l>>temp[i].u;
    sort(all(temp));

    int ans = 1;
    int nt = temp[0].u;
    for(int i=1; i<n; i++){
        if(temp[i].l>nt){
            nt = temp[i].u;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}