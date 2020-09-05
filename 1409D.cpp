#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll t, s, l;

ll total(ll x) {
    ll res = 0;
    while(x) {
        res += x%10;
        x /= 10;
    }
    return res;
}

ll solve(ll x) {
    if(total(x) <= l) return 0;
    else if(x%10 == 0) return solve(x/10) * 10;
    int left = 10-x%10;
    return solve(x+left) + left;
}

int main(){
    fastio
    cin >> t;
    while(t--) {
        cin >> s >> l;
        cout << solve(s) << "\n";
    }
}
