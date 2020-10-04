#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, m, maxlog;
vector<vector<int>> graph, jump;
vector<int> depth, dist, rednodes, newerRed;

void preprocess(int u, int par=0,int d=0) {
    depth[u] = d;
    jump[u][0] = par;
    for(int i=1;i<maxlog;i++) jump[u][i] = jump[jump[u][i-1]][i-1];
    for(int v : graph[u])
        if(v != par)
            preprocess(v, u, d+1);
}

int lca(int u, int v) {
    if(depth[v] > depth[u]) swap(u, v);
    int diff = depth[u] - depth[v];
    for(int i=0;i<maxlog;i++)
        if(diff&(1<<i))
            u = jump[u][i];
    if(u==v) return u;
    for(int i=maxlog-1;i>=0;i--)
        if(jump[u][i] != jump[v][i])
            u = jump[u][i], v = jump[v][i];
    return jump[u][0];
}

int computeDist(int u, int v) {
    return depth[u] + depth[v] - 2*depth[lca(u, v)];
}

void bfs() {
    dist.assign(n, 1e8);
    queue<int> q;
    for(int x : rednodes) {
        dist[x] = 0;
        q.push(x);
    }
    int steps = 0;
    while(!q.empty()) {
        for(int len=q.size();len>0;len--) {
            int cur = q.front(); q.pop();
            for(int nxt : graph[cur])
                if(steps+1 < dist[nxt]) {
                    dist[nxt] = steps+1;
                    q.push(nxt);
                }
        }
        steps++;
    }
}

int main()
{
    fastio
    cin >> n >> m;
    maxlog = ceil(log2(n)+1);
    graph.assign(n, vector<int>());
    jump.assign(n, vector<int>(maxlog));
    depth.assign(n, 0);
    for(int i=0,a,b;i<n-1;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rednodes.push_back(0);
    preprocess(0);
    int sq = sqrt(n);

    // sqrt optimization
    int t, v;
    for(int i=0;i<m;i++) {
        if(i%sq == 0) {
            bfs();
            newerRed.clear();
        }
        cin >> t >> v; v--;
        if(t==1) {
            newerRed.push_back(v);
            rednodes.push_back(v);
        } else {
            int res = dist[v];
            for(int x : newerRed) {
                res = min(res, computeDist(v, x));
            }
            cout << res << "\n";
        }
    }
}
