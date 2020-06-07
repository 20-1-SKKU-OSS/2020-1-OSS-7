#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair

const double MAX_X = 1000000.0;

int N;
vector<pii> li;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        li.push_back(MP(-b,a));
    }
    
    vector<int> x = {0,1,2,3,4,5,6};
    for(int i=8; i<=N; ++i){
        x.push_back(i-1);
        double l = 1/MAX_X/2, r = MAX_X*2, mid, ans;
        int bs_cnt = 0;
        while(bs_cnt < 60){
            mid = (l+r)/2;
            ++bs_cnt;
            sort(x.begin(), x.end(), [&](int a, int b){ return li[a].F*mid+li[a].S > li[b].F*mid+li[b].S; });
            double s = 0;
            for(int j=0; j<8; ++j) s += li[x[j]].F*mid+li[x[j]].S;
            if(s>=0){ ans = mid; l = mid; }
            else r = mid;
        }
        printf("%.12lf\n", ans);
    }
}