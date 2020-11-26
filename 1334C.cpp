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
        vector<ii> monsters(n);
        for(int i=0;i<n;i++) cin >> monsters[i].first >> monsters[i].second;
        monsters.insert(monsters.end(), monsters.begin(), monsters.end());
        ll mn = 1e18, cur = 0;
        for(int i=0;i<2*n;i++) {
            ll explode = i==0 ? 0 : monsters[i-1].second;
            cur += max(monsters[i].first - explode, 0LL);
            if(i>=n-1) {
                mn = min(mn, cur);
                auto v1 = monsters[i-n+1], v2 = monsters[i-n+2];
                cur -= v1.first;
                cur += v2.first;
                cur -= max(v2.first-v1.second, 0LL);
            }
        }
        cout << mn << "\n";
    }
}
