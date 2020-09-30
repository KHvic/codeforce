#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int MAXN = 1e5+5;
vector<int> pars, start, endt, depth;
vector<int> depth_ti[MAXN];
vector<vector<int>> graph, jump;
int n, maxlog;
 
int ti = 0;
void preprocess(int x, int d=0) {
    jump[x][0] = pars[x];
    depth[x] = d;
    depth_ti[d].push_back(ti);
    start[x] = ti++;
    for(int i=1;i<maxlog;i++) jump[x][i] = jump[jump[x][i-1]][i-1];
    for(int v : graph[x]) preprocess(v, d+1);
    endt[x] = ti;
}
 
int kthAncestor(int x, int k) {
    for(int i=0;i<maxlog;i++)
        if(k &(1<<i))
            x = jump[x][i];
    return x;
}
 
int main()
{
    fastio
    cin >> n;
    pars.assign(n, 0);
    start.assign(n, 0);
    endt.assign(n, 0);
    depth.assign(n, 0);
    graph.assign(n, vector<int>());
    maxlog = ceil(log2(n+1));
    jump.assign(n, vector<int>(maxlog, 0));
    vector<int> roots;
    int q, v, p;
    for(int i=0;i<n;i++) {
        cin >> v;
        if(v==0) {
            roots.push_back(i);
            v = i;
        } else {
            v--;
            graph[v].push_back(i);
        }
        pars[i] = v;
    }
    for(int root : roots) preprocess(root);
    cin >> q;
    while(q--) {
        cin >> v >> p; v--;
        int d = depth[v];
        if(d - p < 0) {
            cout << "0";
        } else {
            int ancestor = kthAncestor(v, p);
            int lo = start[ancestor], hi = endt[ancestor];
            int diff = upper_bound(depth_ti[d].begin(), depth_ti[d].end(), hi) - lower_bound(depth_ti[d].begin(), depth_ti[d].end(), lo) - 1;
            cout << diff;
        }
        if(q) cout << " ";
    }
}
