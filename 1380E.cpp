#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 1e6, L = 23;
int n, m, x, y;
vector<int> idxes, cur;
int up[MAXN][L];
int depth[MAXN], prefix[MAXN];
vector<int> graph[MAXN];

void dfs(int x, int par, int d=0) {
    depth[x] = d;
    up[x][0] = par;
    for(int i=1;i<L;i++) up[x][i] = up[up[x][i-1]][i-1];
    for(auto v : graph[x]) dfs(v, x, d+1);
}

int computeLCA(int a, int b) {
    if(depth[b] > depth[a]) swap(a, b);
    int diff = depth[a] - depth[b];
    for(int i=0;i<L;i++)
        if(diff & (1<<i))
            a = up[a][i];
    if(a==b) return a;
    for(int i=L-1;i>=0;i--)
        if(up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    return up[a][0];
}

int main(){
    fastio
    cin >> n >> m;
    idxes.assign(n, 0); cur.assign(m, 0);
    for(int i=0;i<n;i++) cin >> idxes[i], idxes[i]--;
    for(int i=0;i<m;i++) cur[i] = i;
    for(int i=0;i<m-1;i++) {
        cin >> x >> y;
        x--; y--;
        int node = m+i;
        graph[node].push_back(cur[x]);
        graph[node].push_back(cur[y]);
        cur[x] = node;
    }
    dfs(m*2-2, m*2-2);
    for(int i=0;i<n-1;i++) {
        int lca = computeLCA(idxes[i], idxes[i+1]);
        if(lca < m) prefix[0]++;
        else prefix[lca - m + 1]++;
    }
    for(int i=1;i<m;i++) prefix[i] += prefix[i-1];
    for(int i=0;i<m;i++) cout << (n - 1 - prefix[i]) << "\n";
}
