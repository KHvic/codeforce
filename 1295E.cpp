#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

struct ST {
    int n;
    vector<ll> segment, lazy;
    ST(int n):n(n){
        segment.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void updateLazy(int idx, int low, int high) {
        if(lazy[idx] && low != high) {
            lazy[idx*2+1] += lazy[idx];
            lazy[idx*2+2] += lazy[idx];
        }
        // update logic
        if(lazy[idx]) {
            segment[idx] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    void update(int idx, int low, int hi, int qlow, int qhi, ll val) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return;
        else if(low>=qlow && hi<=qhi) {
            lazy[idx] = val;
            updateLazy(idx, low, hi);
        } else {
            int mid = (low+hi) >> 1;
            update(idx*2+1, low, mid, qlow, qhi, val);
            update(idx*2+2, mid+1, hi, qlow, qhi, val);
            segment[idx] = min(segment[idx*2+1], segment[idx*2+2]);
        }
    }

    void update(int qlow, int qhi, ll val) {
        if(qlow>qhi) return;
        update(0, 0, n-1, qlow, qhi, val);
    }

    ll query(int idx, int low, int hi, int qlow, int qhi) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return 1e15;
        else if(low>=qlow && hi<=qhi) return segment[idx];
        int mid = (low+hi) >> 1;
        return min(query(idx*2+1, low, mid, qlow, qhi), query(idx*2+2, mid+1, hi, qlow, qhi));
    }

    ll query(int qlow, int qhi) {
        return query(0, 0, n-1, qlow, qhi);
    }
};

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n), cost(n), pos(n+1);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        pos[vals[i]] = i;
    }
    ST st(n); // cost of partitioning at position i & i+1, where left partitioning only contain < value v
    ll total = 0;
    for(int i=0;i<n;i++) {
        cin >> cost[i];
        total += cost[i];
        st.update(i, i, total);
    }
    ll res = st.query(0, n-2);
    // linesweep, increase value that must be on left partition
    for(int i=1;i<=n;i++) {
        int p = pos[i];
        st.update(p, n-1, -cost[p]); // position that already cover this value
        st.update(0, p-1, cost[p]); // position that need to shift the value to right partition
        res = min(res, st.query(0, n-2));
    }
    cout << res;
}
