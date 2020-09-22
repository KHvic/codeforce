#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef pair<int,int> pii;

int n, m, u, v;
int f; // flow
const int INF = 1e8;
vector<int> parents;
vector<map<int,int>> graph;

void augment(int cur, int mn) {
    if(cur==n) {
        f = mn;
    } else if(parents[cur] != -1) {
        int par = parents[cur];
        augment(par, min(mn, graph[par][cur]));
        graph[par][cur] -= f;
        graph[cur][par] += f;
    }
}

int MF() {
    int mf = 0;
    int t = n+1; // sink
    while(true) {
        f = 0;
        vector<bool> vis(n+2);
        queue<int> q;
        q.push(n);
        parents.assign(n+2, -1);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u==t) break;
            int v, w;
            for(auto& edge : graph[u]) {
                tie(v, w) = edge;
                if(w>0 && !vis[v]) {
                   vis[v] = true;
                   parents[v] = u;
                   q.push(v);
                }
            }
        }
        augment(n+1, INF);
        if(f==0) break;
        mf += f;
    }
    return mf;
}

int main()
{
    fastio
    cin >> n >> m;
    vector<int> vals(n);
    vector<pii> pairs;
    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=0;i<m;i++) {
        cin >> u >> v; u--; v--;
        if(u&1) swap(u, v); // even, odd
        pairs.emplace_back(u, v);
    }
    set<int> primes;
    for(int x : vals) {
        for(int i=2;i*i<=x;i++) {
            if(x%i == 0) {
                primes.insert(i);
                while(x%i==0) x/=i;
            }
        }
        if(x>1) primes.insert(x);
    }
    int res = 0;
    for(int p : primes) {
        graph.assign(n+2, map<int,int>());
        for(int i=0;i<n;i++) {
            int x = vals[i];
            int times = 0;
            while(x%p == 0) {
                x/= p;
                times++;
            }
            // even on source, odd on sink
            if(i&1) graph[i][n+1] = times;
            else graph[n][i] = times;
        }
        for(auto& edge : pairs) {
            tie(u, v) = edge;
            // even to odd
            graph[u][v] = INF;
        }
        res += MF();
    }
    cout << res;
}
