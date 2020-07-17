#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2010;
const int mod = 1e9+7;

vector<int> graph[N];
ll a[N], f[N];
bool visited[N];
int d, n;

// root is the smallest valued node
void dfs(int u, int root) {
    visited[u] = 1;
    f[u] = 1;
    for(int child : graph[u]) {
        if(visited[child]) continue;
        if(a[child] < a[root]) continue; // can't be smaller than root
        if(a[child] - a[root] > d) continue; // break constraint
        if(a[root] == a[child] && child < root) continue; // avoid duplicate
        dfs(child, root);
        // f[u] = multiple(f[child]+1) for all child
        f[u] *= (f[child] +1);
        f[u] %= mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> d >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n-1;i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int res = 0;
    for(int i=0;i<n;i++) {
        fill(f, f+n, 0);
        fill(visited, visited+n, 0);
        // let a[i] be the smallest value
        dfs(i, i);
        res += f[i];
        res %= mod;
    }
    cout << res;
}
