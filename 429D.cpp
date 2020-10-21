#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll ,ll> ii;

int main(){
    fastio
    int n, v;
    cin >> n;
    vector<ii> pts;
    ll sum = 0;
    for(int i=1;i<=n;i++) {
        cin >> v;
        sum += v;
        pts.push_back({i, sum});
    }
    // linesweep
    set<ii> s;// y-axis
    ll res = 1e18;
    for(int i=0, j=0; i<n; i++) {
        ll d = ceil(sqrt(res));
        while(pts[i].first - pts[j].first >= res)
            s.erase({pts[j].second, pts[j++].first});

        auto it = s.lower_bound({pts[i].second - d, pts[i].first});

        // O(1) in theory, same as divide and conquer algorithm
        // at most 7 other points in closest pairs of point
        for(; it != s.end(); it++) {
            ll dx = pts[i].first - it->second;
            ll dy = pts[i].second - it->first;
            ll dist = dx*dx+dy*dy;
            res = min(res, dist);
            if(abs(dy)>d) break;
        }
        s.insert({pts[i].second, pts[i].first});
    }
    cout << res;
}
