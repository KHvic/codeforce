#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, vector<int>> pos;
        for(int i=0,v;i<n;i++) {
            cin >> v;
            pos[v].push_back(i);
        }
        int res = n;
        for(auto& p : pos) {
            auto& vals = p.second;
            int cost = 0;
            for(int i=0;i<vals.size();i++) {
                if(i && vals[i]-1 == vals[i-1]) continue;
                if(vals[i] != 0) cost++;
            }
            int last = vals.back();
            cost += last != n-1;
            res = min(res, cost);
        }
        cout << res << "\n";
    }
}
