#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef pair<int, int> ii;

int main(){
    fastio
    int t,n,v;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        map<int, int> s;
        for(int i=0;i<n;i++) {
            cin >> v;
            vals[i] = v;
            s[v] = i;
        }
        if(s.size() == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int c1 = s.begin()->first, c2 = s.rbegin()->first;
            int idx1 = s.begin()->second, idx2 = s.rbegin()->second;
            vector<ii> res;
            res.emplace_back(idx1+1, idx2+1);
            for(int i=0;i<n;i++) {
                if(i==idx1 || i==idx2) continue;
                if(vals[i] == c1) {
                    res.emplace_back(idx2+1, i+1);
                } else {
                    res.emplace_back(idx1+1, i+1);
                }
            }
            for(auto & p : res) cout << p.first << " " << p.second << "\n";
        }
    }
}
