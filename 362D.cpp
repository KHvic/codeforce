#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, m, p, q;
typedef pair<int, int> pi;

struct UF {
    vector<int> pars;
    vector<pi> any;
    vector<ll> costs;
    int n, cnt;
    UF(int n):n(n) {
        pars.assign(n, 0);
        costs.assign(n, 0);
        any.assign(n, {});
        for(int i=0;i<n;i++) {
            pars[i] = i;
            any[i] = {i, i};
        }
        cnt = n;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int find(int x) {
        return pars[x] == x ? x : pars[x] = find(pars[x]);
    }
    void join(int x, int y) {
        if(connected(x, y)) return;
        int parX = find(x), parY = find(y);
        pars[parX] = parY;
        any[parY] = {parX, parY};
        cnt--;
    }
    void addCost(int x, ll amt) {
        costs[x] += amt;
    }
};

int main()
{
    fastio
    cin >> n >> m >> p >> q;

    UF uf(n);
    int u, v;
    ll w;
    for(int i=0;i<m;i++) {
        cin >> u >> v >> w; u--; v--;
        if(!uf.connected(u, v)) {
            ll total = uf.costs[uf.find(u)] + uf.costs[uf.find(v)];
            uf.join(u, v);
            uf.costs[uf.find(u)] = total;
        }
        uf.addCost(uf.find(u), w);
    }
    int cnt = uf.cnt;
    int join_need = cnt - q;
    if(cnt < q || join_need > p) {
        cout << "NO"; return 0;
    }
    auto cmp = [&](int a, int b) {
        ll valA = uf.costs[a], valB = uf.costs[b];
        return valA > valB;
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for(int i=0;i<n;i++)
        if(uf.find(i) == i)
            pq.push(i);

    vector<pi> res;
    while(p--) {
        if(join_need == 0) {
            while(true) {
                if(pq.empty()) {
                    cout << "NO"; return 0;
                }
                int top = pq.top(); pq.pop();
                tie(u, v) = uf.any[top];
                if(u==v) continue;
                else {
                    res.emplace_back(u+1, v+1);
                    uf.addCost(top, 1000L);
                    pq.push(top);
                    break;
                }
            }
        } else {
            u = pq.top(); pq.pop();
            v = pq.top(); pq.pop();
            res.emplace_back(u+1, v+1);
            ll cost = uf.costs[uf.find(u)] + uf.costs[uf.find(v)];
            uf.join(u, v);
            int root = uf.find(u);
            uf.costs[root] = cost*2LL + 1;
            uf.costs[root] = min(uf.costs[root], (ll)1e9);
            pq.push(root);
            join_need--;
        }
    }
    cout << "YES\n";
    for(int i=0;i<res.size();i++)
        cout << res[i].first << " " << res[i].second << "\n";
}
