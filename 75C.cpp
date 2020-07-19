#include<bits/stdc++.h>
using namespace std;

set<int> computeDivisor(int x) {
    set<int> res;
    for(int i=1;i*i<=x;i++) {
        if(x%i == 0) {
            int a = i, b = x/i;
            res.insert(a);
            res.insert(b);
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a,b,q,l,r;
    cin >> a >> b >> q;
    auto s1 = computeDivisor(a), s2 = computeDivisor(b);
    set<int> intersect;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                      inserter(intersect,intersect.begin()));
    while(q--) {
        cin >> l >> r;
        auto it = upper_bound(intersect.begin(), intersect.end(), r);
        if(it == intersect.begin()) cout << -1 << "\n";
        else {
            it = prev(it);
            int val = *it;
            if(val >= l) cout << val << "\n";
            else cout << -1 << "\n";
        }
    }
}
