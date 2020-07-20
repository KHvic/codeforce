#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,c,p,k,r;
    cin >> n;
    vector<tuple<int,int,int>> groups; // earn, size, index
    for(int i=0;i<n;i++) {
        cin >> c >> p;
        groups.push_back(make_tuple(p,c,i+1));
    }
    sort(groups.begin(), groups.end(), greater<tuple<int,int,int>>());
    cin >> k;
    multiset<int> tables;
    unordered_map<int,vector<int>> tableidx;
    for(int i=0;i<k;i++) {
        cin >> r;
        tables.insert(r);
        tableidx[r].push_back(i+1);
    }
    int res = 0;
    vector<pair<int,int>> selected;
    for(auto group : groups) {
        tie(p,c,r) = group;
        auto low = lower_bound(tables.begin(), tables.end(), c);
        if(low != tables.end()) {
            res += p;
            tables.erase(low);
            selected.push_back({r,tableidx[*low].back()});
            tableidx[*low].pop_back();
        }
    }
    cout << selected.size() << " " << res << "\n";
    for(auto x : selected) {
        tie(p,c) = x;
        cout << p << " " << c << "\n";
    }
}
