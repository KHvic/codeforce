#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n, m;
    cin >> n >> m;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    function<bool(ll)> can = [&](ll x) -> bool {
        ll pplLeft = m;
        ll left = 0;
        for(int i=0;i<n;i++) {
            ll dist = i+1;
            ll boxes = vals[i];
            // use left if have
            left--;
            if(left>0) {
                ll takeLeft = min(left, boxes);
                boxes -= takeLeft;
                left -= takeLeft;
            }
            if(boxes > 0) {
                // at this point, we know left <= 0
                ll remainTime = x-dist; // amount of time left after someone reach this pile
                if(remainTime<=0) return false;
                ll pplNeed = (boxes+remainTime-1)/remainTime;
                pplLeft -= pplNeed;
                if(pplLeft<0) return false;

                left = pplNeed*remainTime - boxes;
            }
        }
        return true;
    };

    ll low = 0, high = 1e15;
    while(low<high) {
        ll mid = (low+high) >> 1;
        if(can(mid)) high = mid;
        else low = mid+1;
    }
    cout << low;
}
