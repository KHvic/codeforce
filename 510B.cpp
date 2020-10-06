#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<string> grid;
vector<vector<bool>> vis;
int n, m;
vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

bool dfs(int x, int y, int px, int py) {
    if(vis[x][y]) return true;
    vis[x][y] = true;
    for(auto d : dirs) {
        int nx = d[0]+x, ny = d[1]+y;
        if(nx<0||ny<0||nx>=n||ny>=m||grid[x][y]!=grid[nx][ny]) continue;
        if((nx!=px || ny != py) && dfs(nx, ny, x, y)) return true;
    }
    return false;
}

int main()
{
    fastio
    cin >> n >> m;
    grid.assign(n, "");
    vis.assign(n, vector<bool>(m));
    for(int i=0;i<n;i++) cin >> grid[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!vis[i][j] && dfs(i, j, i, j)) {
                cout << "Yes"; return 0;
            }
    cout << "No";
}
