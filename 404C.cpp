#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<int,int> pii;
int n,k,v;
int main(){
    fastio
    cin >> n >> k;
    vector<pii> d;
    for(int i=0;i<n;i++) {
        cin >> v;
        d.emplace_back(v, i);
    }
    sort(d.begin(), d.end());
    vector<pii> res;
    vector<int> cnt(n, k);
    map<int, vector<int>> dist;
    if(d[0].first != 0) {
        cout << -1;
        return 0;
    }
    dist[0].push_back(d[0].second);
    for(int i=1;i<n;i++) {
        int j;
        tie(v, j) = d[i];
        if(dist[v-1].empty()) {cout << -1; return 0;}
        cnt[j]--;
        int x = dist[v-1].back();
        if(--cnt[x]==0) dist[v-1].pop_back();
        res.emplace_back(x+1,j+1);
        if(cnt[j]) dist[v].push_back(j);
    }
    cout << res.size() << "\n";
    for(auto& p : res) {
        cout << p.first << " " << p.second << "\n";
    }
}
