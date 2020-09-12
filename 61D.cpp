#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int u,v,w,n;
typedef pair<int,int> pii;
vector<vector<pii>> graph;

ll path(int u, int par) {
    ll res = 0;
    for(auto& edge : graph[u]) {
        if(edge.first == par) continue;
        res = max(res, path(edge.first, u) + edge.second);
    }
    return res;
}

int main(){
    fastio
    cin >> n;
    graph.assign(n, vector<pii>());
    ll cost = 0;
    for(int i=0;i<n-1;i++) {
        cin >> u >> v >> w; u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        cost += 2LL*w;
    }
    ll longestPath = path(0, -1);
    cout << cost - longestPath;
}
