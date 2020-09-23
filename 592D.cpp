#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, k, u, v;

vector<vector<int>> graph;
vector<bool> attacked;

int mxdepth, mxv;

vector<int> attacked_count;

// total edges of minimum subtree containing attacked cities
int find_totaledges(int v, int par) {
    int res = attacked[v];
    int cnt = 0;
    for(int x : graph[v]) {
        if(x==par) continue;
        cnt += find_totaledges(x, v);
        res += attacked_count[x];
        if(attacked_count[x]) cnt++;
    }
    attacked_count[v] = res;
    return cnt;
}


void dfs(int u, int par, int d=0) {
    if(d>mxdepth || (mxdepth==d&&u<mxv)) {
        mxdepth = d, mxv = u;
    }
    for(int x : graph[u]) {
        if(x==par || attacked_count[x]==0) continue;
        dfs(x, u, d+1);
    }
}

pair<int,int> find_diameter() {
    mxdepth = -1;
    dfs(v, -1);
    int start = mxv;
    mxdepth = -1;
    dfs(mxv, -1);
    return {min(start,mxv), mxdepth};
}

int main()
{
    fastio
    cin >> n >> k;
    graph.assign(n, vector<int>());
    attacked.assign(n, false);
    attacked_count.assign(n, 0);
    for(int i=0;i<n-1;i++) {
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i=0;i<k;i++) {
        cin >> v; v--;
        attacked[v] = 1;
    }

    int total = find_totaledges(v, -1);
    int start, diameter;
    tie(start, diameter) = find_diameter();
    cout << start+1 << "\n";
    cout << total*2 - diameter;
}
