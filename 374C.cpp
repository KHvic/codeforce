#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int INF = 1e8;
const int MAXN = 1e3+1;
int dp[MAXN][MAXN];
int n, m;
vector<string> grid;
map<char, char> nxt = {{'D','I'},{'I','M'},{'M','A'},{'A','D'}};
vector<int> dirs[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int dfs(int x, int y) {
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = INF;
    int res = 0;
    char nxtc = nxt[grid[x][y]];
    for(auto d : dirs) {
        int nx = d[0]+x, ny = d[1]+y;
        if(nx<0||ny<0||nx>=n||ny>=m||nxtc!=grid[nx][ny]) continue;
        res = max(res, dfs(nx, ny));
        if(res>=INF) return res;
    }
    if(grid[x][y] == 'A') res++;
    return dp[x][y] = res;
}

int main()
{
    fastio
    cin >> n >> m;
    grid.assign(n, "");
    for(int i=0;i<n;i++) {
        cin >> grid[i];
        for(int j=0;j<m;j++) dp[i][j] = -1;
    }
    int res = 0;
    for(int i=0;i<n&&res<INF;i++)
        for(int j=0;j<m&&res<INF;j++)
            if(grid[i][j] == 'D')
                res = max(res, dfs(i, j));
    if(res == 0) cout << "Poor Dima!";
    else if(res >= INF) cout << "Poor Inna!";
    else cout << res;
}
