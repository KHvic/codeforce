#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct UF {
    vector<int> p, rank, size;
    UF(int N) {
        p = rank = size = vector<int>(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    void join(int i, int j) {
        if (connected(i, j)) return;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

vector<vector<int>> graph;
vector<bool> in_cycle, vis;
stack<int> st;
// cycle detection, at most 1 cycle since n edges with n vertices
void dfs(int x, int par) {
    if(vis[x]) {
        if(in_cycle[x]) return;
        while(1) {
            int top = st.top(); st.pop();
            in_cycle[top] = true;
            if(top == x) break;
        }
    } else {
        vis[x] = true;
        st.push(x);
        for(int v : graph[x])
            if(par != v)
                dfs(v, x);
        if(!st.empty()) st.pop();
    }
}

int main(){
    fastio
    int t, n, a, b;
    cin >> t;
    while(t--) {
        cin >> n;
        graph.assign(n, vector<int>());
        in_cycle = vis = vector<bool>(n);
        for(int i=0;i<n;i++) {
            cin >> a >> b; a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0, 0);
        UF uf(n);
        ll res = 0;
        for(int i=0;i<n;i++)
            for(int nei : graph[i])
                if(!in_cycle[nei])
                    uf.join(i, nei);
        for(int i=0;i<n;i++) {
            int par = uf.find(i);
            ll sz = uf.size[par];
            ll rest = n - sz;
            res += sz-1; // 1 way to each node in subtree
            res += rest*2; // 2 way to other node outside via cycle
        }
        cout << res/2 << "\n";
    }
}
