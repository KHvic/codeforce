#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;
vector<vector<pii>> graph;
vector<int> lcaCount, depth, counter;
vector<vector<int>> up; // binary lifting
vector<int> res;
int n, logn;

void preprocess(int u, int par, int d=0) {
    up[u][0] = par;
    depth[u] = d;
    for(int i=1;i<logn;i++) up[u][i] = up[up[u][i-1]][i-1];
    int v, idx;
    for(auto edge : graph[u]) {
        tie(v, idx) = edge;
        if(v == par) continue;
        preprocess(v, u, d+1);
    }
}

int getLCA(int u, int v) {
    if(depth[v] > depth[u]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0;i<logn;i++)
        if(diff & (1<<i))
            u = up[u][i];
    if(u==v) return u;
    for(int i=logn-1;i>=0;i--)
    if(up[u][i] != up[v][i]) {
        u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}

int solve(int u, int par) {
    int cnt = counter[u] - 2*lcaCount[u];
    int v, idx;
    for(auto edge : graph[u]) {
        tie(v, idx) = edge;
        if(v == par) continue;
        int subcnt = solve(v, u);
        cnt += subcnt;
        res[idx] = subcnt;
    }
    return cnt;
}

int main()
{
    fastio
    cin >> n;
    logn = ceil(log2(n));
    graph.assign(n, vector<pii>());
    lcaCount.assign(n, 0);
    depth.assign(n, 0);
    res.assign(n, 0);
    counter.assign(n, 0);
    up.assign(n, vector<int>(logn, 0));

    int u,v,m;
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].emplace_back(v, i);
        graph[v].emplace_back(u, i);
    }
    preprocess(0, 0);
    cin >> m;
    while(m--) {
        cin >> u >> v; u--; v--;
        counter[u]++; counter[v]++;
        int lca = getLCA(u, v);
        lcaCount[lca]++;
    }
    solve(0, 0);
    for(int i=0;i<n-1;i++) {
        cout << res[i] << " \n"[i==n-1];
    }
}
