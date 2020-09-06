#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;

int main(){
    fastio
    int n,m,s,l;
    cin >> n >> m >> s; s--;
    vector<vector<pii>> graph(n);
    int u,v,w;
    for(int i=0;i<m;i++) {
        cin >> u >> v >> w; u--; v--;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }
    cin >> l;

    vector<int> dist(n,1e9);
    auto cmp = [](auto a, auto b) {
        return a.second > b.second;
    };
    priority_queue<pii,vector<pii>,decltype(cmp)> pq(cmp);
    dist[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()) {
        tie(u,w) = pq.top(); pq.pop();
        if(w > dist[u]) continue;
        for(auto edge : graph[u]) {
            int cost = w + edge.second, v = edge.first;
            if(cost < dist[v]) {
                dist[v] = cost;
                pq.push({v, cost});
            }
        }
    }
    int res = 0;
    for(int u=0;u<n;u++) {
        if(dist[u] == l) res++;

        for(auto edge : graph[u]) {
            int v = edge.first, w= edge.second;
            if(u>v) continue;
            // third condition checks whether if I come from dist[v] to this position
            // is it less than l
            if(dist[u]+w > l && l > dist[u] && w-(l-dist[u])+dist[v] > l) {
                res++;
            }
            // same as previous, but for v
            if(dist[v]+w > l && l > dist[v] && w-(l-dist[v])+dist[u] > l) {
                res++;
            }
            // midpoint check
            if(l > dist[v] && l > dist[u] && dist[u]+dist[v]+w == 2*l) {
                res++;
            }
        }
    }
    cout << res;
}
