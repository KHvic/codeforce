#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n;
    cin >> n;
    vector<pair<ll, ll>> dragons(n);
    for(int i=0;i<n;i++) cin >> dragons[i].first >> dragons[i].second;
    auto cmp = [](auto& a, auto& b) {
//        // cost a then b
//        ll costAB = max(a.first, b.first + a.second);
//        // other way
//        ll costBA = max(b.first, a.first + b.second);
        // can reduce to simpler cost if with some observation that some param is redundant
        ll costAB = a.second - a.first, costBA = b.second - b.first;
        return costAB < costBA;
    };
    sort(dragons.begin(), dragons.end(), cmp);

    ll a, b;
    ll sumB = 0, res = 0;
    for(auto& dragon : dragons) {
        tie(a, b) = dragon;
        res = max(res, sumB+a);
        sumB += b;
    }
    cout << res;
}
