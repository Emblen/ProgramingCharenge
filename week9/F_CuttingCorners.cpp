#include <iostream>
#include <vector>
#include <cmath>
#define PI 3.14159265
using namespace std;

struct vec2{
    double x, y;
};
double dist(vec2 st, vec2 ed){
    return sqrt((st.x-ed.x)*(st.x-ed.x) + (st.y-ed.y)*(st.y-ed.y));
}

double angle(vector<vec2> vp){
    vec2 v1 = vp[0], v2 = vp[1], v3 = vp[2];
    double a = dist(v1, v2), b = dist(v2, v3), c= dist(v3, v1);
    return acos(((a*a)+(b*b)-(c*c))/(2*a*b))*(180/PI);
}

int main(){
    int num; 
    while(cin>>num){
        if(num==0) break;
        vector<vec2> p(num), prep(num);
        for(int i=0; i<num; i++) cin>>p[i].x>>p[i].y;        

        int n = (int)p.size();
        double popang = 0.0;
        
        while(n>=3){
            double minang = 1000.0;
            int mini = -1;
            for(int i=0; i<n; i++){
                vector<vec2> vp = {p[(i+n-1)%n], p[i], p[(i+1)%n]};
                double ang = angle(vp);
                if(ang<minang) {minang = ang; mini = i;}
            }
            if(minang<popang) break;

            popang = minang;
            prep = p;
            p.erase(p.begin()+mini);
            n--;
        }
        cout << (int)prep.size() << " ";
        for(int i=0; i<(int)prep.size(); i++){
            cout << prep[i].x << " " << prep[i].y << " ";
        }
        cout << endl;
    }
    return 0;
}