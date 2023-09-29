#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#define INF 1e9
#define all(x) x.begin(),x.end()
using namespace std;

int div(int n){
    if(n==1) return 0;
    int sum = 1;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            if(i*i==n) {sum += i; break;}
            sum += (i+(n/i));
        }
    }
    return sum;
}

int main(){
    int n;
    while(cin>>n){
        int d = div(n);
        if(d==n) cout << n << " perfect" << endl;
        else if(abs(d-n)<=2) cout << n << " almost perfect" << endl;
        else cout << n << " not perfect" << endl;
    }
    return 0;
}