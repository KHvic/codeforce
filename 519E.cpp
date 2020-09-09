#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, a, b, m, x, y;
int maxn;
vector<int> sz, depth;
vector<vector<int>> up, graph;

// binary lifting preprocessing
void preprocess(int x, int par = 0, int d = 0) {
    depth[x] = d;
    up[x][0] = par;
    sz[x] = 1;
    for(int i=1;i<maxn;i++) up[x][i] = up[up[x][i-1]][i-1];

    for(int child : graph[x]) {
        if(child == par) continue;
        preprocess(child, x, d+1);
        sz[x] += sz[child];
    }
}

int getLCA(int x, int y) {
    if(depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int i=0;i<maxn;i++)
        if((1<<i) & diff)
            x = up[x][i];
    if(x == y) return x;
    for(int i=maxn-1;i>=0;i--) {
        if(up[x][i] != up[y][i]) {
            x = up[x][i], y = up[y][i];
        }
    }
    return up[x][0];
}

int getKthAncestor(int x, int k) {
    for(int i=0;i<maxn;i++)
        if((1<<i)&k)
            x = up[x][i];
    return x;
}

int main(){
    fastio
    cin >> n;
    graph.assign(n, vector<int>());
    for(int i=0;i<n-1;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    maxn = ceil(log2(n));
    sz.assign(n, 0);
    depth.assign(n, 0);
    up.assign(n, vector<int>(maxn));
    preprocess(0);

    auto getDist = [&](int x, int y, int lca) {
        return depth[x] + depth[y] - 2*depth[lca];
    };
    cin >> m;
    for(int t=0;t<m;t++) {
        cin >> x >> y; x--; y--;
        int lca = getLCA(x, y);
        int dist = getDist(x, y, lca);
        if(x==y) {
            cout << n << "\n";
        } else if(dist%2) {
            cout << 0 << "\n";
        } else if(getDist(x, lca, lca) == getDist(y, lca, lca)) {
            int distToLCA = getDist(x, lca, lca);
            cout << n - sz[getKthAncestor(x,distToLCA-1)] - sz[getKthAncestor(y,distToLCA-1)] << "\n";
        } else {
            if(depth[x] < depth[y]) swap(x, y);
            int ancestor1 = getKthAncestor(x, dist/2);
            int ancestor2 = getKthAncestor(x, dist/2-1);
            cout << sz[ancestor1] - sz[ancestor2] << "\n";
        }
    }
}
