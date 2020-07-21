#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    ll vals[n+1];
    for(int i=1;i<=n;i++) cin >> vals[i];
    for(int i=1;i<=n;i++) vals[i] += vals[i-1];
    ll dp[n+1];
    ll dp_idx[n+1];
    ll mx = -1;
    int idx = 0;
    // left max
    for(int i=k;i<=n;i++) {
        ll sum = vals[i] - vals[i-k];
        if(sum > mx) {
            mx = sum;
            idx = i-k+1;
        }
        dp[i] = mx;
        dp_idx[i] = idx;
    }
    mx = -1;
    int a =0, b = 0;
    for(int i=2*k;i<=n;i++) {
        ll left_max = dp[i-k];
        ll sum = vals[i] - vals[i-k];
        sum += left_max;
        if(sum > mx) {
            a = dp_idx[i-k];
            b = i-k+1;
            mx = sum;
        }
    }
    cout << a << " " << b;
}
