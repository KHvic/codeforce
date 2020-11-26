#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// observation: if cycle exist 2, else 1

enum {
    unvisited = 0,
    processing = 1,
    completed = 2
};

vector<int> state;
vector<vector<pair<int, int>>> graph;
vector<int> res;
void dfs(int x) {
    state[x] = processing;
    int idx, v;
    for(auto p : graph[x]) {
        tie(v, idx) = p;
        if(state[v] == unvisited) {
            dfs(v);
            res[idx] = 1;
        }
        else if(state[v] == completed) res[idx] = 1;
        else res[idx] = 2; // cycle
    }
    state[x] = completed;
}

int main(){
    fastio
    int n, m, a, b;
    cin >> n >> m;
    state.assign(n, 0);
    res.assign(m, 0);
    graph.assign(n, vector<pair<int, int>>());
    for(int i=0;i<m;i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].emplace_back(b, i);
    }
    for(int i=0;i<n;i++)
        if(state[i] == unvisited)
            dfs(i);
    cout << *max_element(res.begin(), res.end()) << "\n";
    for(int i=0;i<m;i++) cout << res[i] << " \n"[i==m-1];
}
