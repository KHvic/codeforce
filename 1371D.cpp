#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        // if divisible, can make diff 0
        // else we can make diff 1 for row sum and col sum => total 2
        cout << (k%n == 0 ? "0" : "2") << "\n";

        vector<vector<int>> res(n, vector<int>(n));
        vector<int> colsAssign(n);
        // foreach row
        for(int i=0;i<n;i++) {
            int numAssign = k/n;
            // assign additional leftover
            if(k%n) {
                numAssign++;
                k--;
            }
            priority_queue<vector<int>> cols;
            // select cols to assign greedily
            for(int j=0;j<n;j++) cols.push({-colsAssign[j], j}); // count assigned, index pair
            for(int j=0;j<numAssign;j++) {
                auto col = cols.top(); cols.pop();
                res[i][col[1]] = 1;
                colsAssign[col[1]]++;
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout << res[i][j];
            cout << "\n";
        }
    }
}
