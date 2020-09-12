#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int, int> pii;
const int MAXN = 300005;
vector<pii> edges[MAXN];
int dp[MAXN], tmp[MAXN];
int main()
{
    fastio
    int n, m, u, v, len;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        cin >> u >> v >> len; u--; v--;
        edges[len].emplace_back(u, v);
    }
    for(int i=0;i<MAXN;i++) {
        for(int j=0;j<edges[i].size();j++) {
            tie(u, v) = edges[i][j];
            tmp[v] = max(tmp[v], dp[u] + 1);
        }
        for(int j=0;j<edges[i].size();j++) {
            tie(u, v) = edges[i][j];
            dp[v] = max(dp[v], tmp[v]);
        }
    }
    int res = 0;
    for (int i=0;i<n;i++) res = max(res, dp[i]);
    cout << res;
}
