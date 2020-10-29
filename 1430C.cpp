#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll, ll> ii;

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> vals(n);
        iota(vals.begin(), vals.end(), 1);
        vector<ii> res;
        ll cur = vals.back();
        for(int i=n-2;i>=0;i--) {
            res.emplace_back(cur, vals[i]);
            cur = (cur+vals[i]+1)/2;
        }
        cout << cur << "\n";
        for(auto& p : res) cout << p.first << " " << p.second << "\n";
    }
}
