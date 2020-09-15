#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n ;
    bool valid = true;
    cin >> n;
    vector<string> grids(n);
    for(int i=0;i<n;i++) cin >> grids[i];
    vector<int> mv[5] = {{0,0},{1,0},{2,0},{1,1},{1,-1}};
    for(int i=0;i<n&&valid;i++) {
        for(int j=0;j<n&&valid;j++) {
            if(grids[i][j]=='#') {
                int cnt = 0;
                for(auto m : mv) {
                    int x = i+m[0], y = j+m[1];
                    if(x<0||y<0||x>=n||y>=n) continue;
                    cnt += grids[x][y]=='#';
                    grids[x][y] = '.';
                }
                if(cnt!=5) valid = false;
            }
        }
    }
    cout << (valid ? "YES" : "NO");
}
