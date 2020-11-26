#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// question didn't ask to minimize operations, but it is done here

// precedence of filling will minimize operations
vector<vector<int>> dirs = {{1,1},{1,0},{0,0},{0,1}};

int main(){
    fastio
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin >> mat[i][j];
    auto cnt = [&](int x, int y) {
        int res = 0;
        for(auto d : dirs) {
            int nx = x+d[0], ny = y+d[1];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            res += mat[nx][ny] != 0;
        }
        return res;
    };
    auto chg = [&](int x, int y) {
        for(auto d : dirs) {
            int nx = x+d[0], ny = y+d[1];
            mat[nx][ny] = 2;
        }
    };

    vector<vector<int>> res;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j] == 1) {
                int i2 = i-1, j2 = j-1;
                bool ok2 = false;
                for(auto d : dirs) {
                    int nx = i2+d[0], ny = j2+d[1];
                    int c = cnt(nx, ny);
                    if(c==4) {
                        ok2 = true;
                        chg(nx, ny);
                        res.push_back({nx+1, ny+1});
                        break;
                    }
                }
                if(!ok2) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << res.size() << "\n";
    for(int i=0;i<res.size();i++) cout << res[i][0] << " " << res[i][1] << "\n";
}
