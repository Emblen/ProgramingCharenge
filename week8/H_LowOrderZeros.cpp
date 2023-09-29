#include <iostream>
#include <vector>
using namespace std;

vector<int> vec = {1,1,2,6,4,2,2,4,2,8};
int rec(int n){
    if(n<10) return vec[n];
    if((n/10)%2==0) return (6*rec(n/5)*vec[n%10])%10;
    else return (4*rec(n/5)*vec[n%10])%10;
}

int main(){
    vector<int> input;
    int maxnum = 0;
    int n;
    while(cin>>n){
        if(n==0) break;
        cout << rec(n) << endl;
    }
    return 0;
}