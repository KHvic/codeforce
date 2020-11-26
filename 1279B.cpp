#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll s;
        cin >> n >> s;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        bool removed = false;
        ll mxidx = 0, total = 0;
        int res = 0;
        for(int i=0;i<n;i++) {
            total += vals[i];
            if(vals[i] > vals[mxidx]) mxidx = i;
            if(total > s) {
                if(removed) break;
                removed = true;
                total -= vals[mxidx];
                if(total > s) break;
                res = mxidx+1;
            }
        }
        cout << res << "\n";
    }
}
