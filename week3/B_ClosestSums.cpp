#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(x) x.begin(),x.end()
#define INF 1e9
using namespace std;

//a sum of "two" distinct numbers であることを見逃しており、2^N個の数の組み合わせを考えると勘違いしていた

int main(){
    int n, cnt=1;
    while(cin>>n){
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];

        cout << "Case " << cnt << ":" << endl;
        cnt++;

        int query; cin>>query;

        for(int q=0; q<query; q++){
            int mindiff = INF, ans=INF;
            int cmp; cin>>cmp;
            for(int j=0; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    int tmpsum = a[j]+a[k];
                    int tmpdiff = abs(cmp-tmpsum);
                    // cout << tmpsum << " " <<tmpdiff <<  endl;
                    if(tmpdiff<mindiff){
                        mindiff = tmpdiff;
                        ans = tmpsum;
                    }
                }
            }
            cout << "Closest sum to " << cmp << " is " << ans << "." << endl;
        }         
    }
    return 0;
}