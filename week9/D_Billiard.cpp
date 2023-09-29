#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.14159265
using namespace std;

int main(){
    double a, b, s, m, n; 
    while(cin>>a>>b>>s>>m>>n){
        if(a==0) break;
        double h = b*n, b = a*m;
        cout << fixed << setprecision(2) << atan(h/b)*(180/PI) << " " << sqrt(b*b+h*h)/s << endl;
    }
    //(m+1)*(n+1)の長方形を並べて対角線を引く
    return 0;
}