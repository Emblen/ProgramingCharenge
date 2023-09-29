#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; 
    while(cin>>s){
        if(s==".") break;
        int n = s.length();

        bool isans = false;
        for(int i=1; i<=n/2; i++){
            //約数は300個程度
            if(n%i==0){
                isans = true;
                for(int j=i; j<n; j++){
                    if(s[j]!=s[j-i]){
                        isans = false; 
                        i = j;
                        break;
                    }
                }
                if(isans) {cout << n/i << endl; break;}
            }
        }
        if(isans) continue;
        cout << 1 << endl;
    }
    return 0;
}