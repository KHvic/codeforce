#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
 
const ll mod = 1e9+7;
 
ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e%2) res = res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}
 
int main()
{
    fastio
    int n, x;
    cin >> n >> x;
    ll mx = 0;
    vector<ll> vals(n);
    ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        mx = max(vals[i], mx);
        sum += vals[i];
    }
    ll e = sum - mx;
    map<ll, ll> cnt;
    for(int i=0;i<n;i++) cnt[mx - vals[i]]++;;
 
    int i = 0;
    while(cnt[i] % x == 0) {
        cnt[i+1] += cnt[i]/x;
        i++;
    }
    e += i;
    e = min(e, sum);
    cout << powe(x, e);
}
