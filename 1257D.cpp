#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int, int> ii;
int main(){
    fastio
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> monsters(n);
        int mxp = 0, mxp2 = 0;
        for(int i=0;i<n;i++)
            cin >> monsters[i], mxp = max(mxp, monsters[i]);
        cin >> m;
        vector<ii> heroes, heroes2;
        int p, s;
        for(int i=0;i<m;i++) {
            cin >> p >> s;
            heroes.emplace_back(p, s);
            mxp2 = max(mxp2, p);
        }
        if(mxp > mxp2) {
            cout << "-1\n";
            continue;
        }

        sort(heroes.rbegin(), heroes.rend());
        for(int i=0, mxe=0;i<m;i++) {
            if(heroes[i].second <= mxe) continue;
            mxe = max(mxe, heroes[i].second);
            heroes2.push_back(heroes[i]);
        }
        int res = 0, killed = 0;
        int heroidx = 0, powerneed = 1e9+5;
        auto newday = [&]() {
            heroidx = 0; killed = 1;
            res++; powerneed = 0;
        };
        for(int p : monsters) {
            powerneed = max(p, powerneed);
            // enough power?
            if(heroes2[heroidx].first < powerneed) {
                newday();
                powerneed = p;
            } else if(killed+1 <= heroes2[heroidx].second) {
                // enough endurance?
                killed++;
            } else if(heroidx+1 < heroes2.size() && heroes2[heroidx+1].first >= powerneed) {
                // next hero has enough power?
                heroidx++;
                killed++;
            } else {
                newday();
                powerneed = p;
            }
        }
        cout << res << "\n";
    }
}
