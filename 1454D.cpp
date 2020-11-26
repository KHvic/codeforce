#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll, ll> ii;

int main(){
    fastio
    int t;
    ll n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ii> primes;
        ll mxcnt = 1;
        for(ll i=2;i*i<=n;i++) {
            if(n%i==0) {
                ll cnt = 0;
                while(n%i==0) {
                    cnt++;
                    n/=i;
                }
                mxcnt = max(cnt, mxcnt);
                primes.emplace_back(i, cnt);
            }
        }
        if(n>1) {
            primes.emplace_back(n,1);
        }
        vector<ll> res(mxcnt, 1);
        int m = primes.size();
        ll x, y;
        for(int i=0;i<m;i++) {
            tie(x, y) = primes[i];
            for(int j=0;j<y;j++) res[j] *= x;
        }
        reverse(res.begin(), res.end());
        cout << mxcnt << "\n";
        for(int i=0;i<mxcnt;i++) cout << res[i] << " \n"[i==mxcnt-1];
    }
}
