#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<map<int,int>> graph;
vector<int> node_cost;

int dfs(int x, int par) {
    int cost = 0;
    for(auto p : graph[x]) {
        if(par == p.first) continue;
        cost += dfs(p.first, x) + p.second;
    }
    return cost;
}

void dfs2(int x, int par) {
    // cost of this node => cost of parent + (-1 if cur->par else +1 when par->cur)
    if(par != -1) {
        int parentCost = node_cost[par];
        node_cost[x] = parentCost + (graph[x][par] == 1 ? 1 : -1);
    }
    for(auto p : graph[x]) {
        if(par == p.first) continue;
        dfs2(p.first, x);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    node_cost.assign(n,0);
    graph.assign(n, map<int,int>());
    for(int i=0;i<n-1;i++) {
        cin >> a >> b;
        a--; b--;
        // 0 for outgoing, 1 for incoming
        graph[a][b] = 0;
        graph[b][a] = 1;
    }
    node_cost[0] = dfs(0, -1);
    dfs2(0, -1);
    vector<int> res;
    int best = n;
    for(int i=0;i<n;i++) {
        if(node_cost[i] < best) {
            res.clear(); best = node_cost[i];
        }
        if(node_cost[i] == best) res.push_back(i+1);
    }
    cout << best << "\n";
    for(int i=0;i<res.size();i++) {
        if(i) cout << " ";
        cout << res[i];
    }
}
