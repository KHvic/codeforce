#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll, ll> ii;
int main(){
    fastio
    int t, n;
    ll l, r, s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        vector<ll> left, right;
        vector<ii> emp;
        for(int i=0;i<n;i++) {
            cin >> l >> r;
            left.push_back(l);
            right.push_back(r);
            emp.emplace_back(l, r);
        }
        nth_element(left.begin(), left.begin() + n/2, left.end());
        nth_element(right.begin(), right.begin() + n/2, right.end());
        ll low = left[n/2], hi = right[n/2];

        auto can = [&](ll x) {
            ll cost = 0;
            vector<int> match;
            int smaller = 0;
            for(auto& e : emp) {
                tie(l, r) = e;
                if(x <= r && x >= l) match.push_back(l);
                else {
                    if(x > r) smaller++;
                    cost += l;
                }
            }
            int left = n/2 - smaller;
            sort(match.begin(), match.end());
            for(int i=0;i<match.size();i++) {
                if(i<left) cost += match[i];
                else cost += x;
            }
            return cost <= s;
        };
        while(low<hi) {
            ll mid = (low+hi+1) >> 1;
            if(can(mid)) low = mid;
            else hi = mid-1;
        }
        cout << low << "\n";
    }
}
