#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;
typedef pair<ll,ll> pll;

vector<vector<int>> graph;
vector<int> vals;

pll solve(int v, int par) {
    // without or with 1 at subtree v
    ll with = vals[v], without = 1 - vals[v];
    for(int u : graph[v]) {
        if(u == par) continue;
        ll without2, with2;
        tie(without2, with2) = solve(u, v);

        ll nextwith = 0, nextwithout = 0;

        // case 1: include subtree u
        nextwith += (with * without2) % mod + (without * with2) % mod; // either complement
        nextwith %= mod;
        nextwithout += without * without2; // both without
        nextwithout %= mod;

        // case 2: exclude subtree u (cut edge)
        nextwithout += without * with2; // subtree u must have 1, v without
        nextwithout %= mod;
        nextwith += (with * with2); // subtree u must have 1, v with
        nextwith %= mod;

        with = nextwith; without = nextwithout;
    }
    return {without, with};
}

int main(){
    fastio
    int n, v;
    cin >> n;
    graph.assign(n, vector<int>());
    vals.assign(n, 0);
    for(int i=1;i<=n-1;i++) {
        cin >> v;
        graph[v].push_back(i);
        graph[i].push_back(v);
    }
    for(int i=0;i<n;i++) cin >> vals[i];

    cout << solve(0, -1).second;
}
