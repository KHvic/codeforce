#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ST {
    int n;
    vector<int> segment, lazy;
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
            segment[idx] += (high-low+1)*lazy[idx];
        }
        lazy[idx] = 0;
    }

    void update(int idx, int low, int hi, int qlow, int qhi, int val) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return;
        else if(low>=qlow && hi<=qhi) {
            lazy[idx] = val;
            updateLazy(idx, low, hi);
        } else {
            int mid = (low+hi) >> 1;
            update(idx*2+1, low, mid, qlow, qhi, val);
            update(idx*2+2, mid+1, hi, qlow, qhi, val);
            segment[idx] = segment[idx*2+1] + segment[idx*2+2];
        }
    }

    void update(int qlow, int qhi, int val) {
        update(0, 0, n-1, qlow, qhi, val);
    }

    int query(int idx, int low, int hi, int qlow, int qhi) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return 0;
        else if(low>=qlow && hi<=qhi) return segment[idx];
        int mid = (low+hi) >> 1;
        return query(idx*2+1, low, mid, qlow, qhi) + query(idx*2+2, mid+1, hi, qlow, qhi);
    }

    int query(int qlow, int qhi) {
        return query(0, 0, n-1, qlow, qhi);
    }
};

int main(){
    fastio
    int n, m, v;
    cin >> n >> m;
    vector<int> cur_idx(n), maxpos(n), minpos(n);
    ST st(n+m+1);
    for(int i=0;i<n;i++) {
        cur_idx[n-1-i] = i;
        st.update(i, i, n-1-i);
        maxpos[i] = minpos[i] = i;
    }
    int idx = n;
    for(int i=0;i<m;i++) {
        cin >> v; v--;
        int oldidx = cur_idx[v];
        int newidx = idx++;
        minpos[v] = 0;
        maxpos[v] = max(maxpos[v], st.query(oldidx, oldidx));
        st.update(oldidx+1, newidx-1, 1);
        cur_idx[v] = newidx;
    }
    for(int i=0;i<n;i++) {
        maxpos[i] = max(maxpos[i], st.query(cur_idx[i], cur_idx[i]));
        cout << minpos[i] +1 << " " << maxpos[i] + 1 << "\n";
    }
}
