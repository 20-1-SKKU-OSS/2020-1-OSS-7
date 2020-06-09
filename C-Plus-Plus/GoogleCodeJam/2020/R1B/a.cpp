#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll x, y, a, b;
        scanf("%lld%lld", &x, &y);
        a = abs(x), b = abs(y);
        ll s = 0;
        vector<ll> arr;
        string ans = "";
        for(ll i=1; ; i*=2){
            s += i;
            arr.push_back(i);
            if(s >= a+b) break;
        }
        if((s-a-b)%2){ printf("Case #%d: IMPOSSIBLE\n", tt); continue; }
        s = (s-a-b)/2;
        int l = arr.size();
        for(int i=0; i<l; ++i){
            if(arr[i] & s) arr[i] *= -1;
        }
        for(int i=0; i<l; ++i){
            ll t = abs(arr[i]);
            if(a&t){
                ans += ((arr[i]/t)==x/abs(x))?"E":"W";
                a -= arr[i];
            }
            else{
                ans += ((arr[i]/t)==y/abs(y))?"N":"S";
                b -= arr[i];
            }
        }
        printf("Case #%d: %s\n", tt, ans.c_str());
    }
}