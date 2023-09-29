#include <iostream>
#include <string>
using namespace std;

int main(){
    int k; cin>>k;
    string s, t; cin>>s>>t;
    
    int ans1=0, ans2=0;
    int l = s.length();
    for(int i=0; i<l; i++){
        if(s[i]==t[i]) ans1++;
        else ans2++;
    }
    cout << min(k, ans1) + min(l-k, ans2) << endl;
    return 0;
}