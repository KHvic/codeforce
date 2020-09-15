#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct FT {
    vector<int> ft;
    FT(int n) {
        ft.assign(n+1, 0);
    }
    void adjust(int k, int v) {
        k++;
        for (; k < (int)ft.size(); k += (k&-k)) ft[k] += v;
    }
    int qry(int b) {
        b++;
        int sum = 0;
        for (; b; b -= (b&-b)) sum += ft[b];
        return sum;
    }
};

int n,m,u,v,x,d,t;
vector<vector<int>> graph;
vector<int> depth, chainIdx;

int mx;
void dfs(int u, int par, int d, int chain) {
    mx = max(mx, depth[u] = d);
    chainIdx[u] = chain;
    for(int v : graph[u]) {
        if(v == par) continue;
        dfs(v, u, d+1, chain);
    }
}

int main()
{
    fastio
    cin >> n >> m;
    graph.assign(n, vector<int>());
    depth.assign(n, 0); chainIdx.assign(n, 0);
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int chain = 0, mxd=0;
    vector<FT> chains;
    for(int u : graph[0]) {
        mx = 0;
        dfs(u, 0, 1, chain++);
        chains.push_back(FT(mx+1));
        mxd = max(mxd, mx);
    }
    FT global(mxd+1);

    while(m--) {
        cin >> t >> v; v--;
        int nd = depth[v];
        if(t) {
            int res = 0;
            if(v) {
                chain = chainIdx[v];
                res += chains[chain].qry(nd);
            }
            res += global.qry(nd);
            cout << res << "\n";
        } else {
            cin >> x >> d;
            if(v==0) {
                global.adjust(0, x);
                global.adjust(d+1, -x);
            } else {
                int start = nd-d, end = nd+d+1;
                chain = chainIdx[v];
                if(start <= 0) {
                    int until = abs(start)+1;
                    global.adjust(0, x);
                    global.adjust(until, -x);
                    start = until;
                }
                chains[chain].adjust(start, x);
                chains[chain].adjust(end, -x);
            }
        }
    }
}
