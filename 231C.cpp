#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    sort(vals.begin(), vals.end());
    vector<ll> prefixSum(1,0);
    for(int i=0;i<n;i++) {
        prefixSum.push_back(prefixSum.back() + vals[i]);
    }

    auto can = [&](int target) {
        for(int i=target;i<=n;i++) {
            ll sum = prefixSum[i] - prefixSum[i-target];
            ll toreach = vals[i-1] * target;
            ll cost = toreach - sum;
            if(cost <= k) return vals[i-1];
        }
        return -1LL;
    };

    ll low = 0, high = n;
    ll pos = 0;
    while(low<high) {
        ll mid = low + (high-low)/2 + 1;
        int res = can(mid);
        if(res == -1) {
            high = mid - 1;
        } else {
            low = mid;
            pos = res;
        }
    }
    cout << low << " " << pos;
}
