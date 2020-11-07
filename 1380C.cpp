#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    ll x;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        sort(vals.rbegin(), vals.rend());
        int res = 0;
        for(int i=0,cur=0;i<n;i++) {
            cur++;
            ll score = cur*vals[i];
            if(score>=x) {
                res++;
                cur = 0;
            }
        }
        cout << res << "\n";
    }
}
