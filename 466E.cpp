#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pi;
vector<vector<int>> graph;
vector<int> pars, in, out;
vector<pi> documents;

int timer = 0;
void dfs(int x) {
    in[x] = timer++;
    for(int y : graph[x]) dfs(y);
    out[x] = timer;
}

int find(int x) {
    return pars[x] == x ? x : pars[x] = find(pars[x]);
}

int main()
{
    fastio
    int n,m,t,x,y,d,u;
    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    pars.assign(n+1, 0);
    in.assign(n+1, 0); out.assign(n+1, 0);
    for(int i=1;i<=n;i++) pars[i] = i;

    vector<pi> queries;
    while(m--) {
        cin >> t >> x;
        if(t==1) {
            cin >> y;
            graph[y].push_back(x);
            // y become boss
            pars[x] = find(y);
        } else if(t==2) {
            documents.emplace_back(x, find(x));
        } else {
            cin >> y; y--;
            queries.emplace_back(x, y);
        }
    }
    for(int i=1;i<=n;i++) {
        if(pars[i] == i) dfs(i);
    }
    for(auto& q : queries) {
        tie(u, d) = q;
        tie(x, y) = documents[d];
        bool withinInTime = in[u] >= in[y] && in[u] <= in[x];
        bool withinOutTime = out[u] >= out[x] && out[u] <= out[y];
        if(withinInTime && withinOutTime) cout << "YES\n";
        else cout << "NO\n";
    }
}
