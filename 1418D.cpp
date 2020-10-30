#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, q, v, t;
    cin >> n >> q;

    set<int> trashs;
    multiset<int> gaps;

    auto add = [&](int v) {
        auto it = trashs.insert(v).first;
        auto nxt = next(it);
        if(nxt != trashs.end()) gaps.insert(*nxt - v);

        if(it != trashs.begin()) {
            auto pre = prev(it);
            gaps.insert(v - *pre);
            if(nxt != trashs.end()) gaps.erase(gaps.find(*nxt - *pre));
        }
    };

    auto rmv = [&](int v) {
        auto it = trashs.find(v);
        auto nxt = next(it);
        if(nxt != trashs.end()) gaps.erase(gaps.find(*nxt - v));

        if(it != trashs.begin()) {
            auto pre = prev(it);
            gaps.erase(gaps.find(v - *pre));
            if(nxt != trashs.end()) gaps.insert(*nxt - *pre);
        }
        trashs.erase(it);
    };

    auto query = [&]() {
        if(gaps.empty()) return 0;
        int total = *trashs.rbegin() - *trashs.begin();
        int mxGap = *gaps.rbegin();
        return total - mxGap;
    };

    for(int i=0;i<n;i++) {
        cin >> v;
        add(v);
    }
    cout << query() << "\n";

    while(q--) {
        cin >> t >> v;
        if(t) {
            add(v);
        } else {
            rmv(v);
        }
        cout << query() << "\n";
    }
}
