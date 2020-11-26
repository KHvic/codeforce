#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef tuple<int, int, int> iii;
int main(){
    fastio
    int m,n,k,t,l,r,d;
    cin >> m >> n >> k >> t;
    vector<int> soldiers(m);
    for(int i=0;i<m;i++) cin >> soldiers[i];
    vector<iii> traps;
    for(int i=0;i<k;i++) {
        cin >> l >> r >> d;
        traps.emplace_back(l, r, d);
    }
    sort(traps.begin(), traps.end());
    sort(soldiers.rbegin(), soldiers.rend());

    auto can = [&](int v) {
        if(v==0) return true;
        int mx = soldiers[v-1];
        int cost = n+1;
        int mxr = 0;
        for(auto& trap : traps) {
            tie(l,r,d) = trap;
            if(d<=mx) continue;
            // extend
            if(l<=mxr) {
                cost += max(0, r-mxr)*2;
                mxr = max(r, mxr);
            } else {
                // new
                int len = r-l+1;
                cost += len*2;
                mxr = r;
            }
        }
        return cost <= t;
    };

    int low = 0, hi = m;
    while(low<hi) {
        int mid = (low+hi+1) >> 1;
        if(can(mid)) low = mid;
        else hi = mid-1;
    }
    cout << low;
}
