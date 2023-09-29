#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s1, s2; cin>>s1>>s2;
    int s1l = s1.length(), s2l = s2.length();

    string ans;
    if(s1l>=s2l) ans = s1.substr(0, s1l-(s2l-1)) + "." + s1.substr(s1l-(s2l-1));
    else ans = "0." + string(s2l-s1l-1, '0') + s1;

    while(ans[ans.size()-1]=='0') ans.pop_back();
    if(ans[ans.size()-1]=='.') ans.pop_back();
    cout << ans << endl;

    return 0;
}