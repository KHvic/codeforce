#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
)
int main(){
    fastio
    int t, n, m;
    char c;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> rows(n), cols(m);
        vector<vector<char>> grid(n, vector<char>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> c;
                grid[i][j] = c;
                if(c=='*') rows[i]++, cols[j]++;
            }
        }
        int res = 1e9;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int costr = n-cols[j];
                int costc = m-rows[i];
                int cost = costr+costc - (grid[i][j] == '.');
                res = min(res, cost);
            }
        }
        cout << res << "\n";
    }
}
