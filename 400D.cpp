#include <bits/stdc++.h>
using namespace std;
#define ll long long

// dfs/union-find + floyd warshall
// there exist an edge between two node if dist=0
// check all node of some types is strongly connected

int n, m, k, v, u, x;
vector<int> type, par;
vector<vector<int>> dist;

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void join(int x, int y) {
    int par_x = find(x), par_y = find(y);
    par[par_x] = par_y;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> m >> k;
    type.assign(n,0);
    dist.assign(k, vector<int>(k,1e8));
    for(int i=0,t=0;i<k;i++) {
        dist[i][i] = 0;
        cin >> v;
        fill(type.begin()+t, type.begin()+t+v, i);
        t += v;
    }
    for(int i=0;i<n;i++) par.push_back(i);
    for(int i=0;i<m;i++) {
        cin >> u >> v >> x; u--; v--;
        if(x==0) join(u, v);
        int typex = type[u], typey = type[v];
        dist[typex][typey] = dist[typey][typex] = min(dist[typey][typex], x);
    }
    for(int i=0,cur_par=0;i<n;i++) {
        if(i==0 || type[i] != type[i-1]) cur_par = find(i);
        else if(find(i) != cur_par) {
            cout << "No"; return 0;
        }
    }
    cout << "Yes\n";
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            for(int x=0;x<k;x++)
                dist[j][x] = min(dist[j][x], dist[j][i] + dist[i][x]);
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if(j) cout << " ";
            cout << (dist[i][j] >= 1e8 ? -1 : dist[i][j]);
        }
        cout << "\n";
    }
}
