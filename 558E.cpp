#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// sum segment tree
struct ST {
    int n;
    vector<int> segment, lazy;
    ST(int n):n(n){
        segment.assign(4*n, 0);
        lazy.assign(4*n, -1);
    }

    ST(vector<int>& vals):n(vals.size()) {
        for(int i=0;i<n;i++) update(i, i, vals[i]);
    }

    void updateLazy(int idx, int low, int high) {
        if(lazy[idx] != -1 && low != high) {
            lazy[idx*2+1] = lazy[idx];
            lazy[idx*2+2] = lazy[idx];
        }
        // update logic
        if(lazy[idx] != -1) {
            segment[idx] = (high-low+1)*lazy[idx];
        }
        lazy[idx] = -1;
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
        if(qlow>qhi) return;
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
        if(qlow>qhi) return 0;
        return query(0, 0, n-1, qlow, qhi);
    }
};

int main(){
    fastio
    int n, m, l, r, o;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<ST> st(26, ST(n));
    for(int i=0;i<n;i++) {
        int idx = s[i] - 'a';
        st[idx].update(i, i, 1);
    }
    vector<int> cnt(26);
    while(m--) {
        cin >> l >> r >> o; l--; r--;
        for(int i=0;i<26;i++) {
            cnt[i] = st[i].query(l, r);
            st[i].update(l, r, 0);
        }
        if(o) {
            // increasing
            int left = l;
            for(int i=0;i<26;left+=cnt[i],i++) {
                st[i].update(left, left+cnt[i]-1, 1);
            }
        } else {
            // decreasing
            int right = r;
            for(int i=0;i<26;right-=cnt[i],i++) {
                st[i].update(right-cnt[i]+1, right, 1);
            }
        }
    }
    string res;
    for(int i=0;i<n;i++) {
        for(int j=0;j<26;j++)
        if(st[j].query(i, i)) {
            res += string(1, 'a'+j);
            break;
        }
    }
    cout << res;
}
