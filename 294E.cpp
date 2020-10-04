#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const ll INF = 1e18;

typedef pair<int,ll> pi;
typedef tuple<int,int,ll> ti;
int n;
vector<vector<pi>> graph;
vector<ll> cost, treesize; // cost of all component to x, subtree size of x

void dfs(int x, int par) {
    treesize[x] = 1;
    int u;
    ll w;
    for(auto edge : graph[x]) {
        tie(u, w) = edge;
        if(u==par) continue;
        dfs(u, x);
        treesize[x] += treesize[u];
        cost[x] += cost[u] + w*treesize[u];
    }
}

ll mnCost, sumCost;
void dfs2(int x, int par, ll totalsz) {
    mnCost = min(cost[x], mnCost);
    sumCost += cost[x];
    int u; ll w;
    for(auto edge : graph[x]) {
        tie(u, w) = edge;
        if(u == par) continue;
        ll sz1 = treesize[u], sz2 = totalsz - sz1;
        cost[u] = cost[x] + w*(sz2-sz1);
        dfs2(u, x, totalsz);
    }
}

int main()
{
    fastio
    int a, b;
    ll w;
    cin >> n;
    graph.assign(n, vector<pi>());
    vector<ti> edges;
    for(int i=0;i<n-1;i++) {
        cin >> a >> b >> w; a--; b--;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
        edges.emplace_back(a, b, w);
    }
    ll res = INF;
    for(auto edge: edges) {
        cost.assign(n, 0); treesize.assign(n, 0);
        tie(a, b, w) = edge;
        mnCost = INF, sumCost = 0;
        dfs(a, b);
        ll sizeA = treesize[a];
        dfs2(a, b, sizeA);
        ll mnCostA = mnCost, sumCostA = sumCost/2;

        mnCost = INF, sumCost = 0;
        dfs(b, a);
        ll sizeB = treesize[b];
        dfs2(b, a, sizeB);
        ll mnCostB = mnCost, sumCostB = sumCost/2;

        ll subres = sizeA*sizeB*w + sumCostA + sumCostB + sizeA*mnCostB + sizeB*mnCostA;
        res = min(subres, res);
    }
    cout << res;
}
