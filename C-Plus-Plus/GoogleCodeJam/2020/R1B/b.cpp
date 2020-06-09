#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 500000000;
const ll MM = 1000000000;

ll A, B;

int main()
{
    int T, tt;
    cin >> T >> A >> B;
    for(tt=1; tt<=T; ++tt){
        string res;
        ll x, y;
        for(x=-M; x<=M; x+=M){
            for(y=-M; y<=M; y+=M){
                cout << x << " " << y << endl;
                cin >> res;
                if(res == "CENTER") break;
                if(res == "HIT") break;
            }
            if(res == "CENTER") break;
            if(res == "HIT") break;
        }
        if(res == "CENTER") continue;
        ll lx=-MM, rx=x, midx;
        ll Lx=x, Rx=x;
        while(lx<=rx){
            midx = (lx+rx)/2;
            cout << midx << " " << y << endl;
            cin >> res;
            if(res == "CENTER") break;
            if(res == "HIT"){
                Lx = midx;
                rx = midx-1;
            }
            else{
                lx = midx+1;
            }
        }
        if(res == "CENTER") continue;
        lx = x; rx = MM;
        while(lx<=rx){
            midx = (lx+rx)/2;
            cout << midx << " " << y << endl;
            cin >> res;
            if(res == "CENTER") break;
            if(res == "HIT"){
                Rx = midx;
                lx = midx+1;
            }
            else{
                rx = midx-1;
            }
        }
        if(res == "CENTER") continue;
        x = (Lx+Rx)/2;
        ll ly=-MM, ry=y, midy;
        ll Ly=y, Ry=y;
        while(ly<=ry){
            midy = (ly+ry)/2;
            cout << x << " " << midy << endl;
            cin >> res;
            if(res == "CENTER") break;
            if(res == "HIT"){
                Ly = midy;
                ry = midy-1;
            }
            else{
                ly = midy+1;
            }
        }
        if(res == "CENTER") continue;
        ly = y; ry = MM;
        while(ly<=ry){
            midy = (ly+ry)/2;
            cout << x << " " << midy << endl;
            cin >> res;
            if(res == "CENTER") break;
            if(res == "HIT"){
                Ry = midy;
                ly = midy+1;
            }
            else{
                ry = midy-1;
            }
        }
        if(res == "CENTER") continue;
        y = (Ly+Ry)/2;
        cout << x << " " << y << endl;
        cin >> res;
    }
}