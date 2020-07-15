#include <bits/stdc++.h>
using namespace std;

vector<int> colors;
map<int, unordered_set<int>> neighbors;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,c,a,b;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> c;
        colors.push_back(c);
        neighbors[c];
    }
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a--; b--;
        if(colors[a] == colors[b]) continue;
        neighbors[colors[a]].insert(colors[b]);
        neighbors[colors[b]].insert(colors[a]);
    }
    int best = -1, res = -1;
    for(auto x : neighbors) {
        int cnt = x.second.size();
        if(cnt > best) {
            res = x.first;
            best = cnt;
        }
    }
    cout << res;
}
