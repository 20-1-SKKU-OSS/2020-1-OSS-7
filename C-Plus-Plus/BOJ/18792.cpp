#include<bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
const ui MAX_INDEX = 9999999;

ui N;
vector<ui> arr;

struct A{
    ui val;
    vector<ui> idx;
};

vector<vector<A>> ANS;
int C;

bitset<50000> B[50000];

vector<int> solve_prime(int p, vector<int> idx_list){
    A result = {0,{}};
    vector<int> ret(p-1, 0);
    sort(idx_list.begin(), idx_list.end(), [&](int a, int b){ return ANS[C-1][a].val % p < ANS[C-1][b].val % p; });
    // values: ANS[C-1][idx_list[0]].val ~ ANS[C-1][idx_list[2*p-2]].val
    // return: which index that will not be used
    
    // If number of same value(mod p) is over p, choose that p
    for(int i=0; i<p; ++i){
        if(ANS[C-1][idx_list[i]].val % p == ANS[C-1][idx_list[i+p-1]].val % p){
            for(int j=0; j<2*p-1; ++j){
                if(i<=j && j<i+p){
                    result.val += ANS[C-1][idx_list[j]].val;
                    result.idx.push_back(idx_list[j]);
                }
                else ret[j>i?j-p:j] = idx_list[j];
            }
            result.val /= p;
            ANS[C].push_back(result);
            return ret;
        }
    }

    // Else, use bitset for check S_k

    // if we sort the indexes, we can make pairs: 
    // (idx_list[0], idx_list[0]), (idx_list[1], idx_list[p]), (idx_list[2], idx_list[p+1]), ..., (idx_list[p-1], idx_list[2*p-2])
    // if value(idx_list[x]) == value(idx_list[x+p-1]), there are at least p same values. so value(idx_list[x]) != value(idx_list[x+p-1]) for all x
    B[0] = 0;
    ui a_mod = 0;
    result.val += ANS[C-1][idx_list[0]].val;
    result.idx.push_back(idx_list[0]);
    //vector<bool> isused(2*p-1, false);
    for(int i=0; i<p; ++i){
        a_mod += ANS[C-1][idx_list[i]].val;
        a_mod %= p;
        //isused[i] = true;
    }
    B[0][a_mod] = 1;

    int x;
    for(x=1; x<p; ++x){
        ui d = ANS[C-1][idx_list[x+p-1]].val%p - ANS[C-1][idx_list[x]].val%p;
        B[x] = B[x-1]; // from A
        B[x] |= (B[x-1]<<d) | (B[x-1]>>(p-d)); // from B
        if(B[x][0]) break;
    }
    ui cur=0; int retidx = 0;
    for(int i=p-1; i>x; --i){
        result.val += ANS[C-1][idx_list[i]].val;
        result.idx.push_back(idx_list[i]);
        ret[retidx++] = idx_list[i+p-1];
    }
    for(int i=x; i>=1; --i){ // back-track
        ui d = ANS[C-1][idx_list[i+p-1]].val%p - ANS[C-1][idx_list[i]].val%p;
        ui bef = cur<d?(cur+p-d):(cur-d);
        if(B[i-1][bef]){ // if S_(i-1)[bef] was checked: we will choose number from B, not A
            result.val += ANS[C-1][idx_list[i+p-1]].val;
            result.idx.push_back(idx_list[i+p-1]);
            ret[retidx++] = idx_list[i];
            cur = bef;
        }
        else{
            result.val += ANS[C-1][idx_list[i]].val;
            result.idx.push_back(idx_list[i]);
            ret[retidx++] = idx_list[i+p-1];
        }
    }

    result.val /= p;
    ANS[C].push_back(result);
    return ret;
}

void solve_Cth(int a, int b){
    // ANS[C].val -> ANS[C+1]
    vector<int> idx;
    for(int i=0; i<2*a-1; ++i) idx.push_back(i);
    ++C;
    ANS.push_back(vector<A>());
    for(int r=1; r<2*b; ++r){
        idx = solve_prime(a, idx);
        for(int i=(r+1)*a-1; i<(r+2)*a-1; ++i){
            idx.push_back(i);
        }
    }
}

void back(int count, int i){
    if(ANS[count][i].idx[0] == MAX_INDEX){
        printf("%u ", ANS[count][i].val);
        return;
    }
    for(auto x : ANS[count][i].idx)
        back(count-1, x);
}

int main()
{
    scanf("%u", &N);
    arr.resize(2*N-1,0);
    ANS.push_back(vector<A>());
    for(ui i=0; i<2*N-1; ++i){
        ui x;
        scanf("%u", &x);
        ANS[0].push_back({x,{MAX_INDEX}});
    }
    ui tmp = N;
    for(ui a=2; a*a<=tmp; ){
        if(tmp%a){ a+=(a==2)?1:2; continue; }
        tmp /= a;
        solve_Cth(a, tmp);
    }
    if(tmp>1) solve_Cth(tmp, 1);
    
    back(C, 0);
    printf("\n");
}