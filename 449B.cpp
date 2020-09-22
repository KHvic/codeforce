#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<int, ll> pii;
typedef tuple<ll, bool, int> ti;

int main()
{
    fastio
    int n, m, k, u, v, x;
    cin >> n >> m >> k;
    vector<vector<pii>> graphA(n);
    for(int i=0;i<m;i++) {
        cin >> u >> v >> x; u--; v--;
        graphA[u].emplace_back(v, x);
        graphA[v].emplace_back(u, x);
    }

    vector<ll> dist(n, 1e14);
    vector<bool> hasroute(n);
    priority_queue<ti> pq;
    dist[0] = 0;
    pq.push(make_tuple(0LL, true, 0));
    for(int i=0;i<k;i++) {
        cin >> u >> x; u--;
        if(x < dist[u]) {
            pq.push(make_tuple(-x, false, u));
            dist[u] = x;
            hasroute[u] = true;
        }
    }

    bool notroute;
    ll d, w;
    while(!pq.empty()) {
        tie(d, notroute, x) = pq.top(); pq.pop();
        d = -d;
        if(d > dist[x]) continue;
        for(auto& edge : graphA[x]) {
            tie(v, w) = edge;
            ll cost = d + w;
            if(cost < dist[v] || (cost == dist[v] && hasroute[v])) {
                dist[v] = cost;
                pq.push(make_tuple(-cost, true, v));
                hasroute[v] = false;
            }
        }
    }
    int include = count(hasroute.begin(), hasroute.end(), true);
    cout << k-include;
}
