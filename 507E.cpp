#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5, INF = 1e8;
typedef tuple<int,int,int> ti;

vector<ti> graph[MAXN];
int pre[MAXN], edgeTaken[MAXN], dist[MAXN], cost[MAXN];


int main()
{
    fastio
    int n, m, u, v, z, idx, x;
    cin >> n >> m;
    int cnt = 0;
    vector<ti> roads;
    for(int i=0;i<m;i++) {
        cin >> u >> v >> z;
        u--; v--;
        graph[u].emplace_back(v, z, i);
        graph[v].emplace_back(u, z, i);
        cnt += z;
        if(u>v) swap(u,v);
        roads.emplace_back(u,v,z);
    }
    // assume we are going to destroy everything, cost = cnt
    // when we use not working road, add 1 to cost
    // when we use working road road, subtract 1 to cost
    for(int i=0;i<n;i++) {
        cost[i] = dist[i] = INF;
        pre[i] = -1;
    }

    queue<int> q;
    dist[0] = 0, pre[0] = -1, cost[0] = cnt;
    q.push(0);

    int steps = 0;
    while(!q.empty()) {
        for(int len=q.size();len>0;len--) {
            int cur = q.front(); q.pop();
            int c = cost[cur];
            for(auto edge : graph[cur]) {
                tie(x, z, idx) = edge;
                int nc = c + (z?-1:1);
                if(steps+1 > dist[x]) continue;
                else if(steps+1 < dist[x]) {
                    dist[x] = steps+1;
                    cost[x] = nc;
                    pre[x] = cur;
                    edgeTaken[x] = idx;
                    q.push(x);
                }
                else if(steps+1 == dist[x] && nc < cost[x]) {
                    cost[x] = nc;
                    pre[x] = cur;
                    edgeTaken[x] = idx;
                }
            }
        }
        steps++;
    }
    cout << cost[n-1] << "\n";
    int cur = n-1;
    vector<bool> marked(m);
    while(pre[cur] != -1) {
        int edgeIdx = edgeTaken[cur];
        marked[edgeIdx] = true;
        cur = pre[cur];
    }
    for(int i=0;i<m;i++) {
        tie(u, v, z) = roads[i]; u++; v++;
        if(z) {
            if(!marked[i]) cout << u << " " << v << " 0\n";
        } else {
            if(marked[i]) cout << u << " " << v << " 1\n";
        }
    }
}
