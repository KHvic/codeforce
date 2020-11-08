#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> vals(n);
        ll sum = 0;
        for(int i=0;i<n;i++) {
            cin >> vals[i];
            if((i&1) == 0) sum += vals[i];
        }
        // dp from even position
        ll mx = 0, cur = 0;
        for(int i=0;i+1<n;i+=2) {
            cur += (-vals[i] + vals[i+1]);
            cur = max(cur, 0LL);
            mx = max(cur, mx);
        }
        cur = 0;
        // dp from odd position
        for(int i=1;i+1<n;i+=2) {
            cur += (vals[i] - vals[i+1]);
            cur = max(cur, 0LL);
            mx = max(cur, mx);
        }
        cout << (sum+mx) << "\n";
    }
}
