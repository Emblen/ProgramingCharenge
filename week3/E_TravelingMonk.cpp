#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
#define DIFF 1e-7
#define INF 1e9

struct HT{
    double h,t;
};

int main(){
    int a, d; cin>>a>>d;
    vector<HT> up(a), down(d);
    double height=0.0, time=0.0;

    for(int i=0; i<a; i++){
        cin>>up[i].h>>up[i].t;
        height += up[i].h;
        time += up[i].t;
    }
    for(int i=0; i<d; i++) cin>>down[i].h>>down[i].t;


    double right=time, left=0.0, mid=left, premid=right;
    while(abs(mid-premid)>DIFF){
        premid = mid;
        mid = (left+right)/2;

        double tmpmid=mid, hu=0, hd=0;
        for(int i=0; i<a; i++){
            if(up[i].t<=tmpmid){
                tmpmid -= up[i].t;
                hu += up[i].h;
            }
            else if(tmpmid>0){
                hu += up[i].h/up[i].t*tmpmid;
                break;
            }
        }
        tmpmid=mid;
        for(int i=0; i<d; i++){
            if(down[i].t<=tmpmid){
                tmpmid -= down[i].t;
                hd += down[i].h;
            }
            else if(tmpmid>0){
                hd += down[i].h/down[i].t*tmpmid;
                break;
            }
        }
        // cout << hd << " " << hu << " " << left << " " << right << " " <<mid << endl; 
        if(hu+hd<height) left = mid;
        else right = mid;
        //hu+hd==heightのとき、答えはmid以下である。
    }
    cout << fixed << setprecision(6) << mid << endl;
    return 0;
}