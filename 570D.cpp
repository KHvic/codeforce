#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int, int> pii;
vector<vector<int>> graph;
vector<pii> vertex_time;
string alphas;

const int MAXN = 500001;
vector<int> depthPrefix[MAXN], depthTime[MAXN];

int t = 0;
void dfs(int x, int d=1) {
    int start_time = t++;
    int bits = 1 << (alphas[x] - 'a');
    depthPrefix[d].push_back(bits);
    depthTime[d].push_back(start_time);
    for(int v : graph[x]) {
        dfs(v, d+1);
    }
    int end_time = t-1;
    vertex_time[x] = {start_time, end_time};
}

bool query(int depth, int low, int high) {
    if(low>high) return 1;
    int res = depthPrefix[depth][high] ^ (low == 0 ? 0 : depthPrefix[depth][low-1]);
    return __builtin_popcount(res) <= 1;
}

int main()
{
    fastio
    int n, m, v, h;
    cin >> n >> m;
    graph.assign(n, vector<int>());
    vertex_time.assign(n, {0,0});
    for(int i=1;i<n;i++) {
        cin >> v; v--;
        graph[v].push_back(i);
    }
    cin >> alphas;
    dfs(0);
    for(int i=1;!depthPrefix[i].empty();i++) {
        int len = depthPrefix[i].size();
        for(int j=1;j<len;j++) depthPrefix[i][j] ^= depthPrefix[i][j-1];
    }

    int start, end;
    while(m--) {
        cin >> v >> h; v--;
        tie(start, end) = vertex_time[v];
        auto upper = upper_bound(depthTime[h].begin(), depthTime[h].end(), end);
        auto lower = lower_bound(depthTime[h].begin(), depthTime[h].end(), start);
        if(upper == depthTime[h].begin()) {
            cout << "Yes\n";
        } else {
            int high = prev(upper) - depthTime[h].begin();
            int low = lower - depthTime[h].begin();
            cout << (query(h, low, high) ? "Yes\n" : "No\n");
        }
    }
}
