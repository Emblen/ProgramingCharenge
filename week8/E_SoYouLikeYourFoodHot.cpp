#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s; getline(cin, s);
    vector<string> num(3,"");
    int j = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') j++;
        else if(s[i]=='.') continue;
        else num[j] += s[i];
    }
    int sum = stoi(num[0]), a = stoi(num[1]), b=stoi(num[2]);

    int cnt = 0;
    for(int i=0; i*a<=sum; i++){
        if((sum-a*i)%b==0) {cnt++; cout << i << " " << (sum-a*i)/b << endl;}
    }
    if(cnt==0) cout << "none" << endl;
    return 0;
}