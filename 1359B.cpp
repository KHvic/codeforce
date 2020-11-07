#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, m, x, y;
    cin >> t;
    while(t--) {
        cin >> n >> m >> x >> y;
        vector<string> mat(n);
        for(int i=0;i<n;i++) cin >> mat[i];
        auto add = [&](int l) {
            int cost1 = l*x;
            int cost2 = l/2*y + (l%2)*x;
            return min(cost1, cost2);
        };

        int cost = 0;
        for(auto& s : mat) {
            for(int i=0, cur=0;i<m;i++) {
                cur++;
                if(i==m-1 || s[i] != s[i+1]) {
                    if(s[i] == '.') cost += add(cur);
                    cur = 0;
                }
            }
        }
        cout << cost << "\n";
    }
}
