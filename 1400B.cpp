#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll p, f, s, w, c1, c2;
    cin >> t;
    while(t--) {
        cin >> p >> f >> c1 >> c2 >> s >> w;
        // let w be the smaller one
        if(s<w) {
            swap(w,s);
            swap(c1,c2);
        }

        ll res = 0;
        for(int i=0;i<=c1&&i*s<=p;i++) {
            ll pleft = p-i*s;
            ll takeW = min(c2, pleft/w);
            ll wLeft = c2-takeW;
            ll takeW2 = min(wLeft, f/w);
            ll fleft = f-takeW2*w;
            ll takeS2 = min(c1-i,fleft/s);
            res = max(res, i+takeW+takeW2+takeS2);
        }
        cout << res << "\n";
    }
}
