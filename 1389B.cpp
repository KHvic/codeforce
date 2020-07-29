#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    for(int tc=0;tc<t;tc++) {
        ll n,k,z;
        cin >> n >> k >> z;
        vector<ll> vals(n);
        vector<ll> prefix(1,0);
        for(int i=0;i<n;i++) {
            cin >> vals[i];
            prefix.push_back(prefix.back() + vals[i]);
        }
 
        ll best = prefix[k+1];
        for(int i=0;i<=min(n-2,k);i++) {
            ll left = k-i;
            for(int j=1;j<=z;j++) {
                ll needleft = j*2;
                if(needleft > left) break;
                ll toadd = j *(vals[i] + vals[i+1]);
                ll kleft = left - needleft;
                ll cost = prefix[i+kleft+1] + toadd;
                best = max(cost, best);
            }
        }
        cout << best << "\n";
    }
}
