#include<iostream>
using namespace std;

// Check (x1,y1)->(x2,y2)->(x3,y3) is clockwise or counter-clockwise or collinear
// returns 1 if counter-clockwise
// returns 0 if collinear
// returns -1 if clockwise
int CCW(int x1, int y1, int x2, int y2, int x3, int y3){
    int ccw = x1*y2+x2*y3+x3*y1
             -y1*x2-y2*x3-y3*x1;
    if(ccw>0) return 1;
    if(ccw==0) return 0;
    if(ccw<0) return -1;
}

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cout << "Input x and y of point1." << endl;
    cin >> x1 >> y1;
    cout << "Input x and y of point2." << endl;
    cin >> x2 >> y2;
    cout << "Input x and y of point3." << endl;
    cin >> x3 >> y3;
    int is_ccw = CCW(x1,y1,x2,y2,x3,y3);
    if(is_ccw > 0) cout << "It is Counter-Clockwise." << endl;
    if(is_ccw == 0) cout << "It is Collinear." << endl;
    if(is_ccw < 0) cout << "It is Clockwise." << endl;
    return 0;
}