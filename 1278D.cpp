#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// a tree has at most n-1 edges
// fully connected

int main(){
    fastio
    int n, l, r;
    cin >> n;
    vector<int> endpoints(2*n);
    vector<pair<int, int>> points(n+1);
    for(int i=1;i<=n;i++) {
        cin >> l >> r;
        l--; r--;
        points[i].first = l, points[i].second = r;
        endpoints[l] = i;
        endpoints[r] = -i;
    }
    set<pair<int, int>> active;
    vector<vector<int>> graph(n+1);
    int edgecount = 0;
    for(int i=0;i<2*n;i++) {
        int x = endpoints[i];
        if(x<0) {
            x = -x;
            active.erase({i, x});
        } else {
            r = points[x].second;
            for(auto& p : active) {
                if(p.first >= r) break;
                edgecount++;
                graph[p.second].push_back(x);
                graph[x].push_back(p.second);
                if(edgecount >= n) goto out;
            }
            active.insert({points[x].second, x});
        }
    }
    out:
    if(edgecount != n-1) {
        cout << "NO";
        return 0;
    }
    vector<bool> vis(n+1);
    function<void(int, int)> dfs = [&](int x, int p) {
        vis[x] = true;
        for(int v : graph[x])
            if(!vis[v] && v != p) dfs(v, x);
    };
    dfs(1, -1);
    if(count(vis.begin(), vis.end(), true) == n) cout << "YES";
    else cout << "NO";
}
