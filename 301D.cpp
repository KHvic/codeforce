#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2e5 + 10;

typedef pair<int,int> pi;
vector<pi> queries[MAXN];
vector<int> right_seg[MAXN];
int pos[MAXN];

struct FT {
    vector<ll> ft;
    int n;
    FT(int n):n(n){
        ft.assign(n+1, 0);
    };
    void adjust(int k, ll v) {
        for(++k;k<=n;k+=(k&-k)) ft[k] += v;
    }
    ll query(int k) {
        ll res = 0;
        for(++k;k>0;k-=(k&-k)) res += ft[k];
        return res;
    }
    ll query(int low, int high) {
        return query(high) - query(low-1);
    }
};

int main()
{
    fastio
    int n, m, l, r, v, j;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> v;
        pos[v] = i;
    }
    for(int v=1;v<=n;v++) {
        int j = pos[v];
        for(int i=v;i<=n;i+=v) {
            int l = pos[i], r = j;
            if(r<l) swap(l, r);
            right_seg[r].push_back(l);
        }
    }
    vector<int> res(m);
    for(int i=0;i<m;i++) {
        cin >> l >> r; l--; r--;
        queries[r].emplace_back(l, i);
    }
    FT ft(MAXN);
    for(int i=0;i<MAXN;i++) {
        for(int l : right_seg[i]) {
            ft.adjust(l, 1LL);
        }
        for(auto q : queries[i]) {
            tie(l, j) = q;
            res[j] = ft.query(l, i);
        }
    }
    for(int x : res) cout << x << "\n";
}
