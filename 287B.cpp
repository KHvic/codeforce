#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll suffixSum(ll k, ll len) {
    ll total = k*(k+1)/2;
    ll prefix_len = k-len;
    ll prefix_sum = prefix_len*(prefix_len+1)/2;
    return total - prefix_sum;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    // let m = minimum req
    // n = m*(m-1)/2 + m*(x-1) where x is the smallest splitter required
    n--;k--; // each splitter add k-1
    ll mxpossible = k*(k+1)/2;
    if(n==0) {
        cout << "0"; return 0;
    } else if(n > mxpossible) {
        cout << "-1"; return 0;
    }
    ll low = 1, high = k;
    while(low<high) {
        ll m = (low+high) >> 1;
        ll suffix = suffixSum(k, m);
        if(suffix>=n) {
            // is suffix == n, answer found
            // else: >= n, swap one number to make it = to n
            high = m;
        } else low = m+1;
    }
    cout << low;
}
