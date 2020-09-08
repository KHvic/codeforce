#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, u, v;
vector<vector<int>> graph;
vector<int> res;

vector<int> dfs(int x, int par = -1) {
    vector<int> cnt(26, 0);
    for(int u : graph[x]) {
        if(u == par) continue;
        auto sub = dfs(u, x);
        if(sub.empty()) return {};
        for(int i=0;i<26;i++) cnt[i] += sub[i];
    }
    // allocation step
    int idx = 0;
    int mxdbl = -1;
    // must pick highest rank than those that have multi count
    for(;idx<26;idx++) {
        if(cnt[idx]>=2) mxdbl = idx;
    }
    // pick the first one that do not have any allocation
    for(idx=mxdbl+1;idx<26;idx++) {
        if(cnt[idx]==0) break;
    }
    if(idx == 26) return {};
    res[x] = idx;
    cnt[idx]++;
    // clear all ranks lower than it since there is a 'blockage'
    for(int i=0;i<idx;i++) cnt[i] = 0;
    return cnt;
}

int main(){
    fastio
    cin >> n;
    graph.assign(n,vector<int>());
    res.assign(n,'-');
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto r = dfs(0);
    if(r.empty()) cout << "Impossible!";
    else {
        for(int i=0;i<n;i++) cout << (char)('Z'-res[i]) << " \n"[i==n-1];
    }
}
