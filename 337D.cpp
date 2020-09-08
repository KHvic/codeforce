#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// for each node find furthest distance to marked node, check if this dist is <= d

int n,m,d,v,u;
vector<bool> marked;
vector<int> dist_down, dist_up;
vector<vector<int>> graph;

int dfs(int x, int par) {
    int res = marked[x] ? 0 : -1e8;
    for(int u : graph[x]) {
        if(par == u) continue;
        int subres = dfs(u, x)+1;
        res = max(subres, res);
    }
    return dist_down[x] = res;
}

void dfs2(int x, int par) {
    if(marked[x]) dist_up[x] = max(dist_up[x], 0);
    int mx1 = -1e8, mx2 = -1e8;
    for(int u : graph[x]) {
        if(u == par) continue;
        if(dist_down[u] > mx1) {
            mx2 = mx1;
            mx1 = dist_down[u];
        } else if(dist_down[u] > mx2) {
            mx2 = dist_down[u];
        }
    }
    for(int u : graph[x]) {
        if(u == par) continue;
        // if is the max, take second max bottom
        if(dist_down[u] == mx1) dist_up[u] = mx2 + 2;
        else dist_up[u] = dist_down[x] + 1;
        dist_up[u] = max(dist_up[u], dist_up[x]+1); // also take max of parent
        dfs2(u, x);
    }
}

int main(){
    fastio
    cin >> n >> m >> d;
    dist_down.assign(n, -1e8);
    dist_up.assign(n, -1e8);
    graph.assign(n, vector<int>());
    marked.assign(n, false);
    for(int i=0;i<m;i++) {
        cin >> v; v--;
        marked[v] = 1;
    }
    for(int i=0;i<n-1;i++) {
        cin >> v >> u; v--; u--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1);
    int res = 0;
    for(int i=0;i<n;i++){
        if(max(dist_up[i], dist_down[i]) <= d) res++;
    }
    cout << res;
}
