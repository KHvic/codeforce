#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    if(n==1) {
        cout << -1;
        return 0;
    }
    sort(vals.begin(), vals.end());
    unordered_map<int, vector<int>> diffmap;
    for(int i=0;i<n-1;i++) {
        int diff = vals[i+1] - vals[i];
        diffmap[diff].push_back(vals[i]);
    }
    set<int> res;
    if(diffmap.size() > 2) {
        cout << 0;
        return 0;
    } else if(diffmap.size() == 1) {
        int diff = diffmap.begin()->first;
        res.insert(vals[0] - diff);
        res.insert(vals.back() + diff);
        if(diff%2 == 0 && n == 2) {
            int newdiff = diff/2;
            res.insert(newdiff + vals[0]);
        }
    } else {
        for(auto& p : diffmap) {
            int diff = p.first;
            if(p.second.size() == 1 && diff%2 == 0) {
                int newdiff = diff/2;
                if(newdiff != diff && diffmap.count(newdiff)) {
                    int newval = p.second[0] + newdiff;
                    res.insert(newval);
                }
            }
        }
    }
    cout << res.size() << "\n";
    if(res.size()) {
        for(auto it=res.begin(); it!=res.end(); it++) {
            if(it!=res.begin()) cout << " ";
            cout << *it;
        }
    }
}
