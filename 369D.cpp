#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 3005;
int vals[MAXN];
typedef pair<int,int> pi;
int main()
{
    fastio
    int n, k ,v,u;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
    }
    vector<vector<int>> dist(n+5,vector<int>(n+5));
    vector<int> right(n+1, 0);
    for(int i=n-1;i>=0;i--) {
        right[i] = max(right[i+1], vals[i]);
    }
    ll res = 1;
    queue<pi> q;
    q.push({0, 1});
    dist[0][1] = 1;
    while(!q.empty()) {
        tie(u, v) = q.front(); q.pop();
        if(u>=n || v>=n || dist[u][v] > k) continue;
        int d = dist[u][v];
        // u die, v die
        if(right[v]>0 && vals[u]>0 && dist[v+1][v+2] == 0) {
            dist[v+1][v+2] = d+1;
            q.push({v+1, v+2});
            res++;
        }
        // u die, v survive
        if(right[v]>0 && vals[u] <100 && dist[v][v+1] == 0) {
            dist[v][v+1] = d+1;
            q.push({v, v+1});
            res++;
        }
        // u survive, v die
        if(right[v]<100 && vals[u]>0 && dist[u][v+1] == 0) {
            dist[u][v+1] = d+1;
            q.push({u, v+1});
            res++;
        }
    }
    cout << res;
}
