#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, m, a, b;
vector<vector<int>> graph, dist;

void bfs(int x) {
    vector<bool> vis(n);
    vis[x] = true;
    queue<int> q;
    q.push(x);
    int steps = 0;
    while(!q.empty()) {
        for(int i=q.size();i>0;i--) {
            int top = q.front(); q.pop();
            dist[x][top] = steps;
            for(int v : graph[top]) {
                if(vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }
        steps++;
    }
}

int main()
{
    fastio
    cin >> n >> m;
    graph.assign(n, vector<int>());
    dist.assign(n, vector<int>(n, 1e8));
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0;i<n;i++) bfs(i);
    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--; t1--; s2--; t2--;

    int res = 1e8;
    if(dist[s1][t1] <= l1 && dist[s2][t2] <= l2) {
        res = dist[s1][t1] + dist[s2][t2];
    }
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            int d = dist[i][j];
            int d2 = min(dist[s1][i]+dist[j][t1]+d, dist[s1][j]+dist[i][t1]+d);
            int d3 = min(dist[s2][i]+dist[j][t2]+d, dist[s2][j]+dist[i][t2]+d);
            if(d2 <= l1 && d3 <= l2) {
                res = min(res, d2+d3-d);
            }
        }
    }
    res = m - res;
    cout << (res < 0 ? -1 : res);
}
