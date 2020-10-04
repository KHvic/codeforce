#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e6, blk_size = 500;
int n, m;
int cnt[MAXN];
vector<int> vals, in, out, invert;
vector<vector<int>> graph;
int ft[MAXN];

void adjust(int k, int v) {
    for(++k;k<=n;k+=(k&-k)) ft[k] += v;
}

int query(int k) {
    int res = 0;
    for(++k;k>0;k-=(k&-k)) res += ft[k];
    return res;
}

int query(int lo, int hi) {
    return query(hi) - query(lo-1);
}


struct Query {
    int l, r, idx, v;
    Query(){}
    Query(int l, int r, int idx, int v):l(l),r(r),idx(idx),v(v){}
    bool operator<(Query other) const {
        int v1 = l/blk_size, v2 = other.l/blk_size;
        if(v1 != v2) return v1 < v2;
        return v1&1 ? (r < other.r) : (r > other.r);
    }
}qs[MAXN];


void add(int k) {
    int v = vals[invert[k]];
    adjust(cnt[v], -1);
    adjust(++cnt[v], 1);
}

void rmv(int k) {
    int v = vals[invert[k]];
    adjust(cnt[v]--, -1);
    adjust(cnt[v], 1);
}

int timer = -1;
void dfs(int x, int par=-1) {
    in[x] = ++timer;
    invert[timer] = x;
    for(int u : graph[x]) {
        if(u == par) continue;
        dfs(u, x);
    }
    out[x] = timer;
}

int main()
{
    fastio
    cin >> n >> m;
    vals.assign(n, 0);
    graph.assign(n, vector<int>());
    in.assign(n, 0);
    out.assign(n, 0);
    invert.assign(n, 0);
    for(int i=0;i<n;i++) cin >> vals[i];

    int a, b;
    for(int i=0;i<n-1;i++) {
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(0);
    vector<int> res(m);
    for(int i=0;i<m;i++) {
        cin >> a >> b; a--; b;
        qs[i] = Query(in[a],out[a],i,b);
    }
    sort(qs, qs+m);
    int curL = 0, curR = -1;
    for(int i=0;i<m;i++) {
        Query q = qs[i];
        while(curL > q.l) add(--curL);
        while(curR < q.r) add(++curR);
        while(curL < q.l) rmv(curL++);
        while(curR > q.r) rmv(curR--);
        res[q.idx] = query(q.v, n);
    }
    for(int i=0;i<m;i++) cout << res[i] << "\n";
}
