#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(){
    int p, t; cin>>p>>t;
    vector<set<int>> opinion(p);
    int cnt=0, i, j;
    while(cin>>i>>j){
        i--; j--;
        opinion[i].insert(j);
        cnt++;
        if(cnt==p*t) break;
    }

    set<set<int>> setnum; 
    for(int i=0; i<p; i++) setnum.insert(opinion[i]);
    cout << setnum.size() << endl;

    return 0;
}