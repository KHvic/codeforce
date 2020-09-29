#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int, int> pi;
int n, q;
vector<int> vals;
vector<vector<int>> graph, divs;

void setDivisors(int idx) {
    int v = vals[idx];
    divs[idx].clear();
    for(int i=2;i*i<=v;i++) {
        if(v%i==0) {
            divs[idx].push_back(i);
            while(v%i==0) {v/=i;}
        }
    }
    if(v>1) divs[idx].push_back(v);
}

const int MAXN = 2e6 + 5;
set<pi> divSet[MAXN];
vector<pi> query;
void dfs(int x, int pars, int depth=0) {
    query[x] = {-1, -1};
    for(int div : divs[x]) {
        if(!divSet[div].empty()) query[x] = max(query[x], *divSet[div].rbegin());
        divSet[div].insert({depth, x+1});
    }
    for(int v : graph[x])
        if(v != pars)
            dfs(v, x, depth+1);
    for(int div : divs[x]) {
        divSet[div].erase({depth, x+1});
    }
}

int main()
{
    fastio
    cin >> n >> q;
    vals.assign(n, 0); query.assign(n, {-1, -1});
    graph.assign(n, vector<int>());
    divs.assign(n, vector<int>());
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        setDivisors(i);
    }
    int u, v;
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1);
    int t;
    while(q--) {
        cin >> t >> v; v--;
        if(t==1) {
            cout << query[v].second << "\n";
        } else {
            cin >> u;
            vals[v] = u;
            setDivisors(v);
            dfs(0, -1);
        }
    }
}
