#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int n;
vector<int> cost;
vector<vector<int>> graph, rgraph;
vector<bool> vis;
stack<int> st;

const int mod = 1e9+7;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = true;
    for(int u : graph[x]) dfs(u);
    st.push(x);
}

vector<int> leader;
vector<int> leaderMinCost, minCostTimes;
void dfs2(int x, int root) {
    if(vis[x]) return;
    vis[x] = true;
    leader[x] = root;
    if(leaderMinCost[root] > cost[x]) {
        minCostTimes[root] = 0;
        leaderMinCost[root] = cost[x];
    }
    if(cost[x] == leaderMinCost[root]) minCostTimes[root]++;
    for(int u : rgraph[x]) dfs2(u, root);
}

int main(){
    fastio
    cin >> n;
    cost.assign(n, 0); graph.assign(n, vector<int>());
    rgraph.assign(n, vector<int>());
    leader.assign(n, 0); leaderMinCost.assign(n,2*1e9);
    minCostTimes.assign(n,0);
    for(int i=0;i<n;i++) cin >> cost[i];
    int m, u, v;
    cin >> m;
    for(int i=0;i<m;i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    // kosaraju
    vis.assign(n, false);
    for(int i=0;i<n;i++) dfs(i);
    vis.assign(n, false);
    while(!st.empty()) {
        int x = st.top(); st.pop();
        if(vis[x]) continue;
        dfs2(x, x);
    }

    ll res = 0;
    ll pathCnt = 1;
    for(int i=0;i<n;i++)
        if(leader[i] == i) {
            res += leaderMinCost[i];
            pathCnt *= minCostTimes[i];
            pathCnt %= mod;
        }
    cout << res << " " << pathCnt;
}
