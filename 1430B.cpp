#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        sort(vals.rbegin(), vals.rend());
        ll res = accumulate(vals.begin(), vals.begin()+k+1, 0LL);
        cout << res << "\n";
    }
}
