#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    vector<vector<int>> right(m);
    for(int i=0;i<n;i++) {
        cin >> grid[i];
        int count_one = 0;
        for(int j=m-1;j>=0;j--) {
            if(grid[i][j] == '1') count_one++;
            else count_one = 0;
            right[j].push_back(count_one);
        }
    }
    int res = 0;
    for(int i=0;i<m;i++) {
        sort(right[i].begin(), right[i].end(), greater<int>());
        int width = INT_MAX;
        for(int j=0;j<n;j++) {
            width = min(width, right[i][j]);
            res = max(res, width*(j+1));
        }
    }
    cout << res;
}
