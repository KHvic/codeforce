#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 1e6+50;
int vals[MAXN];
ll cnt[MAXN];
ll res = 0;
ll ans[MAXN];

const int blk_size = 500;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        int v1 = l/blk_size, v2 = other.l/blk_size;
        if(v1 != v2) return v1 < v2;
        return v1&1 ? (r < other.r) : (r > other.r);
    }
}qs[MAXN];

void rmv(int idx) {
    int v = vals[idx];
    ll count = cnt[v];
    res -= count*count*v;
    cnt[v] = --count;
    res += count*count*v;
}

void add(int idx) {
     int v = vals[idx];
     ll count = cnt[v];
     res -= count*count*v;
     cnt[v] = ++count;
     res += count*count*v;
}

int main()
{
    int n, t;
    fastio
    cin >> n >> t;

    for(int i=0;i<n;i++) cin >> vals[i];
    for(int i=0;i<t;i++) {
        cin >> qs[i].l >> qs[i].r; qs[i].l--; qs[i].r--;
        qs[i].idx = i;
    }
    sort(qs, qs+t);
    int curL = 0, curR = -1;
    for(int i=0;i<t;i++) {
        Query q = qs[i];
        while(curL > q.l) add(--curL);
        while(curR < q.r) add(++curR);
        while(curL < q.l) rmv(curL++);
        while(curR > q.r) rmv(curR--);
        ans[q.idx] = res;
    }

    for(int i=0;i<t;i++) cout << ans[i] << "\n";
}
