#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int solve(vector<int> aset, vector<int>bset){
    int numa=1, numb=100, ans=0;
    while(numa<=100 && numb>0){
        if(!aset[numa]) numa++;
        else{
            if(!bset[numb]) numb--;
            else{
                int diff = aset[numa]-bset[numb];
                ans = max(ans, numa+numb);
                if(diff==0){
                    aset[numa]=0; bset[numb]=0;
                    numa++; numb--;
                }
                else if(diff>0){
                    aset[numa] = diff;
                    numb--;
                }
                else{
                    bset[numb] = -diff;
                    numa++;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> aset(101,0), bset(101,0);
    for(int i=0; i<n; i++){
        int a, b; cin>>a>>b;
        aset[a]++; bset[b]++;

        cout << solve(aset, bset) << endl;
    }
    return 0;
}