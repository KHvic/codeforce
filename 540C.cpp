#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, x1, x2, y1, y2;
vector<string> grid;
vector<vector<bool>> vis;
vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool dfs(int x, int y) {
    queue<vector<int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()) {
        auto top = q.front(); q.pop();
        x = top[0], y = top[1];
        if(x==x2 && y==y2) return 1;
        for(auto d : dirs) {
            int nx = x+d[0], ny = y+d[1];
            if(nx<0||ny<0||nx>=n||ny>=m||vis[nx][ny]) continue;
            if((nx!=x2 || ny!=y2) && grid[nx][ny] == 'X') continue;
             vis[nx][ny] = 1;
             q.push({nx,ny});
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    string in;
    for(int i=0;i<n;i++) {
        cin >> in;
        grid.push_back(in);
    }
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    vis.assign(n, vector<bool>(m));
    bool reachable = dfs(x1, y1);
    if(!reachable) {
        cout << "NO";
        return 0;
    }
    int cnt_intact = 0;
    for(auto d : dirs) {
        int x = x2+d[0], y = y2+d[1];
        if(x<0||y<0||x>=n||y>=m) continue;
        cnt_intact += (grid[x][y] == '.' || (x==x1&&y==y1)); // can treat as intact if starting is neighbor
    }
    // case 1: same start and end, just need an intact neighbor
    if(x1 == x2 && y1 == y2) {
        cout << (cnt_intact > 0 ? "YES" : "NO");
        return 0;
    }
    int need = grid[x2][y2] == '.' ? 2 : 1;

    if(cnt_intact >= need) cout << "YES";
    else cout << "NO";
}
