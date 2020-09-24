#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// idea 1: 1+2+3...x = x*(x+1)/2, thus we know that there are roughly at most sqrt(N) numbers that can fulfill the condition
// First, track all candidates where count[i] >= i (roughly at most sqrtN such candidates)
// for each candidate perform partial sum queries for each of the query => O(NsqrtN)

// idea 2: segment tree + sorting of queries, sliding of values

struct Query {
    int l, r, idx;
    Query(int l, int r, int idx):l(l),r(r),idx(idx){}
    bool operator<(Query other) {
        return r < other.r;
    }
};

struct ST {
    vector<int> st;
    int n;
    ST(int n):n(n) {
        st.assign(2*n, 0);
    }
    void update(int idx, int v) {
        st[idx+n] = v;
        for(int i=(idx+n)>>1;i>0;i>>=1)
            st[i] = st[i*2] + st[i*2+1];
    }
    int query(int l, int r) {
        int res = 0;
        for(l+=n, r+=n; l<=r; l>>=1, r>>=1) {
            if(l%2) res += st[l++];
            if((r%2)==0) res += st[r--];
        }
        return res;
    }
};

const int MAXN = 1e5+5;
vector<int> occurence[MAXN];

int main()
{
    fastio
    int n, k, l, r;
    cin >> n >> k;
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    vector<Query> qs;
    for(int i=0;i<k;i++) {
        cin >> l >> r; l--; r--;
        qs.emplace_back(l, r, i);
    }
    sort(qs.begin(), qs.end());

    int j = 0;
    vector<int> res(k);
    ST st(n);
    for(int i=0;i<n;i++) {
        int v = vals[i];
        if(v>n) continue;
        occurence[v].push_back(i);
        int freq = occurence[v].size();
        if(freq >= v) {
            int last = freq - v;
            int pos = occurence[v][last];
            st.update(pos, 1);
        }
        if(freq >= v+1) {
            int last = freq - v - 1;
            int pos = occurence[v][last];
            st.update(pos, -1); // cancel out 1 if range query reaches this index
        }
        if(freq >= v+2) {
            int last = freq - v - 2;
            int pos = occurence[v][last];
            st.update(pos, 0); // clear previous -1 position
        }
        while(j<k && qs[j].r == i) {
            res[qs[j].idx] = st.query(qs[j].l, i);
            j++;
        }
    }
    for(int x : res) cout << x << "\n";
}
