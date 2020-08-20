#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n,m,k;
    cin >> n >> m >> k;
    ll low = 1, high = n*m;

    function<ll(ll x)> smallerCnt = [&](ll x) -> ll {
        ll res = 0;
        x--;
        for(int i=1;i<=n;i++) {
            res += min(x/i, m); // need to limit to m numbers for this row
        }
        return res;
    };
    while(low<high) {
        ll mid = (low+high+1) >> 1;
        if(smallerCnt(mid) >= k) high = mid - 1;
        else low = mid;
    }
    cout << low;
}
