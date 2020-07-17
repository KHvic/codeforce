#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, q, l, r;
    cin >> n >> q;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    vector<int> prefixSum(n);
    for(int i=0;i<q;i++) {
        cin >> l >> r;
        l--; r--;
        prefixSum[l]++;
        if(r+1<n) prefixSum[r+1]--;
    }
    for(int i=1;i<n;i++) prefixSum[i] += prefixSum[i-1];
    sort(vals.begin(), vals.end(), greater<int>());
    sort(prefixSum.begin(), prefixSum.end(), greater<int>());
    ll res = 0;
    for(int i=0;i<n;i++)
        res += prefixSum[i] * vals[i];
    cout << res;
}
