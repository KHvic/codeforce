#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    int low = 1e9, high = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> table[i][j], low = min(low, table[i][j]), high = max(high, table[i][j]);
        }
    }
    function<bool(int)> can = [&](int tar) -> bool {
        bool seen[m][m];
        memset(seen, 0, sizeof seen);
        for(int i=0;i<n;i++) {
            vector<int> indexes;
            for(int j=0;j<m;j++) {
                if(table[i][j] >= tar)
                    indexes.push_back(j);
            }
            for(int j=0;j<indexes.size();j++)
                for(int k=j+1;k<indexes.size();k++) {
                    int v1 = indexes[j], v2 = indexes[k];
                    if(seen[v1][v2]) return true;
                    else seen[v1][v2] = true;
                }
        }
        return false;
    };
    while(low<high) {
        int mid = (low+high+1) >> 1;
        if(can(mid)) low = mid;
        else high = mid-1;
    }
    cout << low;
}
