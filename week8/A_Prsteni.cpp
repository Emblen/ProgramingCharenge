#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    int a; cin>>a;
    for(int i=1; i<n; i++){
        int b; cin>>b;
        int div = __gcd(a, b);
        cout << a/div << "/" << b/div << endl;
    }
    return 0;
}