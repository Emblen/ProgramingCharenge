#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int testcase; cin>>testcase;
    for(int t=0; t<testcase; t++){
        int k, n; cin>>k>>n;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin>>s[i];

        string cmp = s[0];
        for(int i=1; i<n; i++){
            int cl = cmp.length();
            string plus = "";

            for(int j=0; j<k; j++){
                string subcmp = cmp.substr(cl-s[i].length());
                if(subcmp == s[i]) break;
                else{
                    plus += s[i].back();
                    s[i].pop_back();
                }
            }
            reverse(all(plus));
            cmp += plus;
        }
        cout << cmp.length() << endl;
    }
    return 0;
}