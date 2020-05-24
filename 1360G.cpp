#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,m,a,b;
    cin.sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b;
        if(n*a != m*b) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            vector<string> res(n,string(m,'0'));
            vector<int> cnt(m);
            for(int i=0;i<n;i++) {
                vector<pair<int,int>> cols;
                for(int j=0;j<m;j++) {
                    if(cnt[j] < b) cols.push_back({cnt[j], j});
                }
                // sort by frequency
                sort(cols.begin(), cols.end());
                // select a number of col for this row
                for(int j=0;j<a;j++) {
                    int col = cols[j].second;
                    cnt[col]++;
                    res[i][col] = '1';
                }
            }
            for(int i=0;i<n;i++) cout << res[i] << endl;
        }
    }
}
