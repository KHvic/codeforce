#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<int,int> pii;
int n, x, y, t;
vector<vector<pii>> graph;
vector<int> subset;

int dfs(int u, int par) {
    int res = 0;
    for(auto& edge : graph[u]) {
        if(edge.first == par) continue;
        int subres = dfs(edge.first, u);
        if(edge.second > subres) {
            subset.push_back(edge.first+1);
            subres = edge.second;
        }
        res += subres;
    }
    return res;
}

int main(){
    fastio
    cin >> n;
    graph.assign(n, vector<pii>());
    for(int i=0;i<n-1;i++) {
        cin >> x >> y >> t; x--; y--; t--;
        graph[x].emplace_back(y, t);
        graph[y].emplace_back(x, t);
    }
    cout << dfs(0, -1) << "\n";
    for(int i=0;i<subset.size();i++)
        cout << subset[i] << " \n"[i==subset.size()-1];
}
