#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<ll, ll> ii;

map<string, int> idxMap;
vector<ii> words, dp;
vector<int> rep;
map<int, vector<int>> graph, rgraph;
vector<set<int>> newGraph;

void lower(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

int newIdx(string& s) {
    ll cnt = count(s.begin(), s.end(), 'r');
    words.emplace_back(cnt, s.size());
    return idxMap[s] = words.size()-1;
}

int getIdx(string& s) {
    return idxMap.count(s) ? idxMap[s] : newIdx(s);
}

ii solve(int idx) {
    if(dp[idx].first != -1) return dp[idx];
    ii res = words[idx];
    for(int nxt : newGraph[idx]) res = min(res, solve(nxt));
    return dp[idx] = res;
}

stack<int> st;
vector<bool> vis;
void dfs1(int x) {
    vis[x] = true;
    for(int v : graph[x])
        if(!vis[v])
            dfs1(v);
    st.push(x);
}

void dfs2(int x, int r) {
    vis[x] = true;
    rep[x] = r;
    words[r] = min(words[r], words[x]);
    for(int v : rgraph[x])
        if(!vis[v])
            dfs2(v, r);
}

int main(){
    fastio
    int m, n;
    cin >> m;
    string a, b;
    vector<int> init;
    for(int i=0;i<m;i++) {
        cin >> a;
        lower(a);
        init.push_back(getIdx(a));
    }
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        lower(a); lower(b);
        int idxA = getIdx(a), idxB = getIdx(b);
        graph[idxA].push_back(idxB);
        rgraph[idxB].push_back(idxA);
    }

    // kosaraju
    int sz = words.size();
    vis.assign(sz, false);
    for(int i=0;i<sz;i++)
        if(!vis[i])
            dfs1(i);
    vis.assign(sz, false);
    rep.assign(sz, 0);
    while(!st.empty()) {
        int top = st.top(); st.pop();
        if(!vis[top]) dfs2(top, top);
    }
    newGraph.assign(sz, set<int>());
    for(auto& p : graph) {
        int from = rep[p.first];
        for(auto to : p.second) {
            to = rep[to];
            if(to != from) newGraph[from].insert(to);
        }
    }

    // dp
    dp.assign(sz, {-1, -1});
    ll res1 = 0, res2 = 0;
    for(int x : init) {
        auto subres = solve(rep[x]);
        res1 += subres.first, res2 += subres.second;
    }
    cout << res1 << " " << res2;
}
