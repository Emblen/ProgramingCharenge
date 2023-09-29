#include <iostream>
#include <string>
using namespace std;

int main(){
    int testcase; cin>>testcase; 
    for(int t=0; t<testcase; t++){
        string s; cin>>s;
        int n = s.length();

        int ans = 0;
        bool isok = true;
        for(int i=0; i<n/2; i++){
            char left = s[i], right = s[n-1-i];
            if(left==right) continue;

            int lj = i+1, rj = n-i-2;
            bool isrj = true;
            // cout << lj << " " << rj << endl;
            while(i!=rj){
                if(left==s[rj]) break;
                if(right==s[lj]) {isrj = false; break;}
                rj--; lj++;
            }
            if(i==rj) {isok = false; break;}
            
            if(isrj){
                ans += n-1-i-rj;
                for(rj; rj<n-1-i; rj++) swap(s[rj], s[rj+1]);
            }
            else{
                ans += lj-i;
                for(lj; lj>i; lj--) swap(s[lj], s[lj-1]);
            }
        }
        if(isok) cout << ans << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}