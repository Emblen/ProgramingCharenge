#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool pairsort(string left, string right){
    return left.substr(0,2) < right.substr(0,2);
}

int main(){
    int n; cin>>n;
    while(n){
        vector<string> names;
        for(int i=0; i<n; i++){
            string name; cin>>name;
            names.push_back(name);
        }
        stable_sort(names.begin(), names.end(), pairsort);
        for(auto v:names) cout << v << endl;
        cout << endl;
        cin>>n;
    }
    return 0;
}