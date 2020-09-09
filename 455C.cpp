#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct UF {
    vector<int> pars;
    vector<int> sz;
    void init(int n) {
        pars.assign(n, -1);
        sz.assign(n, 1);
    }
    int find(int x) {
        return pars[x] == x ? x : pars[x] = find(pars[x]);
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    void join(int a, int b) {
        if(connected(a,b)) return;
        a = find(a), b = find(b);
        // take longer side of both components size
        int pathsz = (sz[a]+2)/2 + (sz[b]+2)/2; // find 2 to include mid node
        int mxsz = max(sz[a], max(sz[b], pathsz)); // assign maximum path so far
        pars[a] = pars[b];
        sz[b] = mxsz;
    }
    int getMaxPath(int x) {
        return sz[find(x)];
    }
};

int n,m,q,a,b,t;
vector<vector<int>> graph;
vector<bool> visited;

int mxdepth = 0;
int mx = 0;
UF uf;

void dfs(int x, int rep, int depth = 1, int par = -1) {
    uf.pars[x] = rep;
    if(depth>mxdepth) {
        mxdepth = depth;
        mx = x;
    }
    for(int child : graph[x]) {
        if(child == par) continue;
        dfs(child, rep, depth+1, x);
    }
}

int findDiameter(int x) {
    mxdepth = 0;
    dfs(x, x);
    mxdepth = 0;
    dfs(mx, x);
    return uf.sz[x] = mxdepth;
}

int main(){
    fastio
    cin >> n >> m >> q;
    uf.init(n);
    visited.assign(n, false);
    graph.assign(n, vector<int>());
    for(int i=0;i<m;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(uf.pars[i] == -1) findDiameter(i);
    }

    for(int i=0;i<q;i++) {
        cin >> t;
        if(t==1) {
            cin >> a; a--;
            cout << uf.getMaxPath(a)-1 << "\n";
        } else {
            cin >> a >> b; a--; b--;
            uf.join(a, b);
        }
    }
}
