#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct ST {
    int n;
    vector<int> s4, s7, s47, s74, lazy;
    ST(string& vals) {
        n = vals.size();
        s4.assign(4*n, 0);
        s7.assign(4*n, 0);
        s47.assign(4*n, 0);
        s74.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(vals, 0, 0, n-1);
    }
    void build(string& vals, int idx, int low, int high) {
        if(low>high) return;
        if(low==high) {
            s4[idx] = vals[low] == '4';
            s7[idx] = vals[low] == '7';
            s47[idx] = s74[idx] = 1;
            return;
        }
        int mid = (low+high)/2;
        build(vals, idx*2+1, low, mid);
        build(vals, idx*2+2, mid+1, high);
        s4[idx] = s4[idx*2+1] + s4[idx*2+2];
        s7[idx] = s7[idx*2+1] + s7[idx*2+2];
        s47[idx] = max(s47[idx*2+1] + s7[idx*2+2], max(s4[idx*2+1] + s7[idx*2+2], s4[idx*2+1] + s47[idx*2+2]));
        s74[idx] = max(s74[idx*2+1] + s4[idx*2+2], max(s7[idx*2+1] + s4[idx*2+2], s7[idx*2+1] + s74[idx*2+2]));
    }

    void updateLazy(int idx, int low, int high) {
        if(lazy[idx] && low != high) {
            lazy[idx*2+1] ^= lazy[idx];
            lazy[idx*2+2] ^= lazy[idx];
        }
        // update logic
        if(lazy[idx]) {
            swap(s4[idx], s7[idx]);
            swap(s47[idx], s74[idx]);
        }
        lazy[idx] = 0;
    }

    void update(int idx, int low, int hi, int qlow, int qhi) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return;
        else if(low>=qlow && hi<=qhi) {
            lazy[idx] = 1;
            updateLazy(idx, low, hi);
        } else {
            int mid = (low+hi) >> 1;
            update(idx*2+1, low, mid, qlow, qhi);
            update(idx*2+2, mid+1, hi, qlow, qhi);
            s4[idx] = s4[idx*2+1] + s4[idx*2+2];
            s7[idx] = s7[idx*2+1] + s7[idx*2+2];
            s47[idx] = max(s47[idx*2+1] + s7[idx*2+2], max(s4[idx*2+1] + s7[idx*2+2], s4[idx*2+1] + s47[idx*2+2]));
            s74[idx] = max(s74[idx*2+1] + s4[idx*2+2], max(s7[idx*2+1] + s4[idx*2+2], s7[idx*2+1] + s74[idx*2+2]));
        }
    }

    void update(int qlow, int qhi) {
        update(0, 0, n-1, qlow, qhi);
    }

};

int main()
{
    fastio
    int n, m, l, r;
    string s;
    cin >> n >> m >> s;
    ST st(s);
    while(m--) {
        cin >> s;
        if(s=="count") {
            cout << st.s47[0] << "\n";
        } else {
            cin >> l >> r; l--; r--;
            st.update(l, r);
        }
    }
}
