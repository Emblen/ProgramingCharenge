#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#define INF 1e9
#define all(x) x.begin(),x.end()
#define PI 3.14159265
using namespace std;


int main(){
    double r, h, s;
    while(cin>>r>>h>>s){
        if(r==0 && h==0 && s==0) break;
        double deg = 360 - 2*acos(r/h)*(180/PI);
        cout << fixed << setprecision(2) << (2*r*PI*deg/360)*(1+s*0.01) + (2*(sqrt(h*h-r*r)))*(1+s*0.01) << endl;
    }
    return 0;
}