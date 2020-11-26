#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 998244353;

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res = res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}

int main(){
    fastio
    int n, k;
    cin >> n;
    map<int, int> cnt;
    vector<vector<int>> ppls(n);
    for(int i=0;i<n;i++) {
        cin >> k;
        ppls[i] = vector<int>(k);
        for(int j=0;j<k;j++) {
            cin >> ppls[i][j];
            cnt[ppls[i][j]]++;
        }
    }
    ll invn = powe(n, mod-2);
    ll total = 0;
    for(int i=0;i<n;i++) {
        ll sum = 0;
        for(int x : ppls[i]) {
            ll prob = 1LL*cnt[x]*invn%mod;
            (sum += prob) %= mod;
        }
        total += sum*powe(ppls[i].size(), mod-2);
       total %= mod;
    }
    total = total*invn%mod;
    cout << total;
}
