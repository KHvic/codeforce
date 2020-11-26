#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int n, m;
    cin >> n >> m;
    int t = (1<<m) - 1;
    vector<vector<int>> vals(n, vector<int>(m));
    int low = 0, hi = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> vals[i][j];
            hi = max(hi, vals[i][j]);
        }
    }

    auto can = [&](int v) -> pair<int, int> {
        set<int> bits; // at most 2^m = 256 size
        map<int, int> idxmap;
        for(int i=0;i<n;i++) {
            int b = 0;
            for(int x : vals[i]) {
                b <<= 1;
                b += (x>=v);
            }
            bits.insert(b);
            idxmap[b] = i;
        }
        for(auto it=bits.begin();it!=bits.end();it++) {
            for(auto it2=it;it2!=bits.end();it2++)
                if((*it2 | *it) == t) {
                    return {idxmap[*it], idxmap[*it2]};
                }
        }
        return {-1, -1};
    };

    while(low < hi) {
        int mid = (low+hi+1) >> 1;
        if(can(mid).first != -1) low = mid;
        else hi = mid-1;
    }
    auto res = can(low);
    cout << res.first+1 << " " << res.second+1;
}
