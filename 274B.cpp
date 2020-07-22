#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<vector<int>> edges;
vector<ll> vals;

vector<ll> solve(int idx, int par) {
    ll dec = 0, inc = 0;
    // must solve for child before we solve parent
    for(int child : edges[idx]) {
        if(child == par) continue;
        auto subres = solve(child, idx);
        dec = max(dec, subres[0]);
        inc = max(inc, subres[1]);
    }
    ll val = vals[idx] - dec + inc;
    // if val is positive, we need to decrease
    if(val > 0) dec += val;
    else inc -= val; // need to increase
    return {dec, inc};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a, b;
    cin >> n;
    edges.assign(n, vector<int>());
    for(int i=0;i<n-1;i++) {
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        cin >> a;
        vals.push_back(a);
    }
    auto res = solve(0, 0);
    cout << res[0] + res[1];
}
