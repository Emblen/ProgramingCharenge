#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int n; cin>>n;
        priority_queue<pair<int, int>> buying;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> selling;
        int askp = INF, bidp = 0, stockp = INF;

        for(int j=0; j<n; j++){
            bool isbuy = false;
            pair<int, int> tmp;
            string s0, s1, s2; 
            cin >> s0 >> tmp.second >> s1 >> s2 >> tmp.first;
            if(s0=="buy") isbuy = true;

            if(isbuy){
                buying.push(tmp);
                bidp = max(bidp, tmp.first);
            }
            else{
                selling.push(tmp);
                askp = min(askp, tmp.first);
            }

            while(true){
                if(buying.empty() || selling.empty()) break;
                pair<int, int> fbuy = buying.top();
                pair<int, int> fsel = selling.top();

                if(fbuy.first>=fsel.first){
                    buying.pop(); selling.pop();
                    int diff = fbuy.second - fsel.second;
                    if(diff<0){
                        fsel.second = -diff;
                        selling.push(fsel);
                    }
                    else if(diff>0){
                        fbuy.second = diff;
                        buying.push(fbuy);
                    }
                    stockp = fsel.first;
                }
                else break;

                if(!buying.empty()) bidp = buying.top().first;
                else bidp = 0;
                if(!selling.empty()) askp = selling.top().first;
                else askp = INF;
            }
            if(askp==INF) cout << "- "; else cout << selling.top().first << " ";
            if(!bidp) cout << "- "; else cout << buying.top().first << " ";
            if(stockp==INF) cout << "- "; else cout << stockp << endl; 
        }
    }
    return 0;
}