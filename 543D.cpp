#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;
vector<vector<int>> graph;
vector<ll> ways, res;
vector<vector<ll>> prefix, suffix;
int n, v;

void dfs(int x, int par) {
    ll res = 1;
    for(int v : graph[x]) {
        if(v == par) continue;
        dfs(v, x);
        res = res*(1+ways[v])%mod;
    }
    ways[x] = res;
    int pre = 1, suf = 1;
    int len = graph[x].size();
    for(int i=0;i<len;i++) {
        int to = graph[x][i], to2 = graph[x][len-i-1];
        prefix[x].push_back(pre);
        suffix[x].push_back(suf);
        pre = pre*(ways[to]+1)%mod;
        suf = suf*(ways[to2]+1)%mod;
    }
    reverse(suffix[x].begin(), suffix[x].end());
}

void dfs2(int x, int par, ll parWays) {
    res[x] = ways[x] * (parWays+1) % mod;
    for(int i=0;i<graph[x].size();i++) {
        int to = graph[x][i];
        if(to == par) continue;
        ll otherWays = prefix[x][i] * suffix[x][i] % mod * (parWays+1) % mod;
        dfs2(to, x, otherWays);
    }
}

int main(){
    fastio
    cin >> n;
    graph.assign(n, vector<int>());
    res = ways = vector<ll>(n);
    prefix = suffix =  vector<vector<ll>>(n);
    for(int i=1;i<n;i++) {
        cin >> v; v--;
        graph[i].push_back(v);
        graph[v].push_back(i);
    }
    dfs(0, 0);
    dfs2(0, 0, 0);
    for(int i=0;i<n;i++) cout << res[i] << " \n"[i==n-1];
}
