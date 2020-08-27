#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> vals;
vector<int> segtree;
int n,m,l,r,q;

void build() {
    segtree.assign(n*2, 0);
    for(int i=0;i<n;i++) segtree[i+n] = vals[i];
    for(int i=n-1;i>0;i--) segtree[i] = segtree[i*2] & segtree[i*2+1];
}

int query(int l, int r) {
    int res = 0xFFFFFFFF;
    for(l+=n,r+=n;l<=r;l>>=1,r>>=1) {
        if(l&1) res &= segtree[l++];
        if((r&1) == 0) res &= segtree[r--];
    }
    return res;
}

typedef tuple<int,int,int> tii;

int main(){
    fastio
    cin >> n >> m;
    vals.assign(n, 0);

    int prefixcnt[n+1][31];
    memset(prefixcnt, 0, sizeof prefixcnt);
    vector<tii> constraints;
    for(int i=0;i<m;i++) {
        cin >> l >> r >> q; l--; r--;
        for(int j=0;j<31;j++)
        if(q&(1<<j)) {
            prefixcnt[l][j]++;
            prefixcnt[r+1][j]--;
        }
        constraints.emplace_back(l,r,q);
    }
    for(int i=0;i<n;i++) {
        int val = 0;
        for(int j=0;j<31;j++) {
            if(i) prefixcnt[i][j] += prefixcnt[i-1][j];
            if(prefixcnt[i][j]) val |= (1<<j);
        }
        vals[i] = val;
    }

    // use segment tree to validate constraints
    build();
    for(auto& c : constraints) {
        tie(l, r, q) = c;
        if(query(l, r) != q) {
            cout << "NO"; return 0;
        }
    }
    cout << "YES\n";
    for(int i=0;i<n;i++) cout << vals[i] << " \n"[i==n-1];
}
