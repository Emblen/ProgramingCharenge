#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    string input;
    while(getline(cin, input)){
        if(input=="") break;
        string s = "";
    
        for(int i=0; i<input.length(); i++) {
            if(input[i]==' ') continue;
            s += input[i];
        }
        s += "$";
        int n = s.length();

        vector<pair<string, int>> sa(n);
        for(int i=0; i<n; i++){
            sa[i] = {s, i};
            s = s.substr(1);
        }
        sort(all(sa));
        vector<int> ref(n);
        for(int i=0; i<n; i++) ref[sa[i].second] = i;

        vector<int> LCP(n+1, 0);
        int j = 0, lcp = 0, maxlcp = 0;
        //前の操作で一致した文字数を保持するのでO(N)
        for(int i=0; i<n-1; i++){
            string s1 = sa[ref[i]].first, s2 = sa[ref[i]-1].first;
            int maxj = min(s1.length(), s2.length());

            while(j<maxj && s1[j]==s2[j]) {lcp++; j++;}
            LCP[ref[i]] = lcp;
            maxlcp = max(maxlcp, lcp);
            lcp = max(0, lcp-1);
            j = lcp;
        }
        LCP[n] = 0;

        vector<int> num(maxlcp+1, 0);
        for(int i=1; i<=maxlcp; i++){
            int tmp = 0;
            for(int j=1; j<n; j++){
                if(LCP[j]>=i) num[i] = max(num[i], ++tmp);
                else tmp = 0;
            }
            cout << num[i]+1 << endl;
        }
        cout << endl;
    }
    return 0;
}