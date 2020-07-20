#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k;
    ll l,r,d;
    cin >> n >> m >> k;
    ll prefixM[m+1];
    ll prefixN[n+1];
    ll vals[n];
    vector<tuple<ll,ll,ll>> ops;
    memset(prefixM, 0, sizeof prefixM);
    memset(prefixN, 0, sizeof prefixN);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
    }
    for(int i=0;i<m;i++) {
        cin >> l >> r >> d;
        l--; r--;
        ops.push_back(make_tuple(l, r, d));
    }
    for(int i=0;i<k;i++) {
        cin >> l >> r;
        l--; r--;
        prefixM[l]++;
        prefixM[r+1]--;
    }
    for(int i=1;i<m;i++) prefixM[i] += prefixM[i-1];
    for(int i=0;i<m;i++) {
        tie(l,r,d) = ops[i];
        ll times = prefixM[i];
        prefixN[l] += d*times;
        prefixN[r+1] -= d*times;
    }
    for(int i=1;i<n;i++) prefixN[i] += prefixN[i-1];
    for(int i=0;i<n;i++) {
        prefixN[i] += vals[i];
        if(i) cout << " ";
        cout << prefixN[i];
    }
}
