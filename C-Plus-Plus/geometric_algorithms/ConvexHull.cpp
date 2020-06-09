#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// Same function in Counter_ClockWise.cpp
int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int ccw = x1*y2+x2*y3+x3*y1
             -y1*x2-y2*x3-y3*x1;
    if(ccw>0) return 1;
    if(ccw==0) return 0;
    if(ccw<0) return -1;
}

// Returns the id of quadrant which (x,y) is in.
// 0 for (x,y)==(0,0)
// 1 for   0<=degree<90
// 2 for  90<=degree<180
// 3 for 180<=degree<270
// 4 for 270<=degree<360
int quad(int x, int y){
    if(x==0 && y==0) return 0;
    if(y==0) return x>0?1:3;
    if(x==0) return y>0?2:4;
    if(x>0 && y>0) return 1;
    if(x<0 && y>0) return 2;
    if(x<0 && y<0) return 3;
    if(x>0 && y<0) return 4;
}

struct Point{
    int x, y;
};

const int MAX_VALUE = 2100000000;

vector<Point> P;

int main()
{
    int N;
    cout << "Input the number of points(N>=3): " << endl;
    cin >> N;
    cout << "Input x and y value of N points" << endl;
    for(int i=0; i<N; ++i){
        int x, y;
        cin >> x >> y;
        P.push_back({x,y});
    }
    // Find the lowest point -> We will set this point as Origin
    int lx, ly=MAX_VALUE;
    for(auto p : P){
        if(p.y < ly) lx=p.x, ly=p.y;
        else if(p.y == ly && p.x < lx) lx = p.x;
    }
    // Sort points as counter-clockwise order
    sort(P.begin(), P.end(), [&](Point &a, Point &b)->bool{
        int qa = quad(a.x-lx, a.y-ly);
        int qb = quad(b.x-lx, b.y-ly);
        if(qa!=qb) return qa < qb;
        return CCW(a.x, a.y, lx, ly, b.x, b.y) < 0;
    });
    // Get Convex Hull
    vector<Point> CH;
    int si = 0;
    for(int i=0; i<N; ++i){
        while(si >= 2 && CCW(CH[si-2].x, CH[si-2].y, CH[si-1].x, CH[si-1].y, P[i].x, P[i].y) <= 0){
            CH.pop_back();
            --si;
        }
        CH.push_back(P[i]); ++si;
    }

    // Print Convex Hull
    cout << "The Number of Points on Convex Hull: " << CH.size() << endl;
    for(auto chp : CH) cout << chp.x << " " << chp.y << endl;
    
    return 0;
}