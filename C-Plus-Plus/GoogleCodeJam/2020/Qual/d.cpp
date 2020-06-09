#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt, T, B;
    cin >> T;
    cerr << "testcase number: " << T << endl;
    for(tt=1; tt<=T; ++tt){
        cin >> B;
        cerr << tt << "th start" << endl;
        string s(B, '0');
        int q=0;
        for(int i=0; i<B; ++i){
            ++q;
            cout << i+1 << endl;
            string xx;
            cin >> xx; char x = xx[0];
            cerr << xx << endl;
            if(q%10==1){ --i; continue; }
            s[i] = x;
        }
        string tmp;
        while(q<150){ cout << 1 << endl; ++q; cin >> tmp; cerr << tmp << endl;}
        cout << s << endl;
        string result;
        cin >> result;
        if(result == "N") break;
    }
}