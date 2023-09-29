#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    string s; cin>>s;
    string ans = s;
    int l = s.length();
    for(int i=1; i<=l-2; i++){
        for(int j=1; j<=l-i-1; j++){
            string s1, s2, s3, rs;
            s1 = s.substr(0, i);
            s2 = s.substr(i, j);
            s3 = s.substr(i+j, l);
            reverse(all(s1)); reverse(all(s2)); reverse(all(s3));
            rs = s1+s2+s3;
            if(rs<ans) ans = rs;
        }
    }
    cout << ans << endl;
    return 0;
}