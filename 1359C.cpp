#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int tc;
    ll h, c;
    double t;
    cin >> tc;
    while(tc--) {
        cin >> h >> c >> t;
        if(t==h) {
            cout << "1\n";
            continue;
        } else if(t <= (h+c)/2.0) { // converge to this minimum
            cout << "2\n";
            continue;
        }

        auto f = [&](int x) {
            double nom = (h+c)*x + h;
            double dem = x*2 + 1;
            return nom/dem;
        };
        int lo = 0, hi = 1e9;
        while(lo<=hi) {
            int mid = (lo+hi) >> 1;
            double midf = f(mid);
            if(midf>t) lo = mid+1;
            else hi = mid-1;
        }
        vector<pair<double, int>> res;
        for(int i=max(0,lo-5);i<=lo+5;i++)
            res.emplace_back(abs(f(i)-t), i*2+1);
        sort(res.begin(), res.end());
        cout << res[0].second << "\n";
    }
}
