#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 998244353;
typedef pair<int, int> ii;

int main(){
    fastio
    int n, a, b;
    cin >> n;
    vector<ll> fac(1,1);
    for(int i=1;i<=n;i++) fac.push_back(fac[i-1]*i % mod);
    vector<ii> vals;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        vals.emplace_back(a, b);
    }
    ll res = fac[n];
    sort(vals.begin(), vals.end(), [](auto& a, auto& b) {return a.second < b.second;});
    ll first = 1;
    for(int i=0, cnt=0;i<n;i++) {
        cnt++;
        if(i==n-1 || vals[i].second != vals[i+1].second) {
            first = first * fac[cnt] % mod;
            cnt = 0;
        }
    }
    sort(vals.begin(), vals.end());
    ll second = 1, both = 1;
    bool bothInc = true;
    for(int i=0, cnt1=0, cnt2=0;i<n;i++) {
        cnt1++; cnt2++;
        if(i==n-1 || vals[i].first != vals[i+1].first) {
            second = second * fac[cnt1] % mod;
            cnt1 = 0;
        }
        if(i==n-1 || vals[i] != vals[i+1]) {
            both = both * fac[cnt2] % mod;
            cnt2 = 0;
        }
        if(i) bothInc &=
            (vals[i].first >= vals[i-1].first && vals[i].second >= vals[i-1].second);
    }
    if(!bothInc) both = 0;
    res = ((res-first)%mod-second)%mod+both;
    res = (res%mod+mod)%mod;
    cout << res;
}
