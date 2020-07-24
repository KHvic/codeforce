#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    int countChild = 0;
    int lazy = 0;
    vector<int> val; // sum
    Node() {
        val.assign(32, 0);
    }

    ll getSum() {
        ll res = 0;
        for(int i=0;i<32;i++) {
            res += 1LL * val[i] * (1LL << i);
        }
        return res;
    }
};

vector<Node> segment;
vector<int> vals;
int n, q, o, l, r, x;

void updateLazy(int idx, int low, int high) {
    if(segment[idx].lazy && low != high) {
        int mid = (low+high)/2;
        segment[idx*2+1].lazy ^= segment[idx].lazy;
        segment[idx*2+2].lazy ^= segment[idx].lazy;
    }
    // lazy update logic
    if(segment[idx].lazy) {
        for(int i=0;i<32;i++) {
            bool bit = segment[idx].lazy & (1<<i);
            if(bit) {
                segment[idx].val[i] = segment[idx].countChild - segment[idx].val[i];
            }
        }
    }
    segment[idx].lazy = 0;
}

void build(int idx, int low, int high) {
    segment[idx].lazy = 0;
    if(low > high) return;
    if(low == high) {
        for(int i=0;i<32;i++) segment[idx].val[i] += ((vals[low] >> i) & 1);
        segment[idx].countChild = 1;
        return;
    }
    int mid = (low+high)/2;
    build(idx*2+1, low, mid);
    build(idx*2+2, mid+1, high);
    segment[idx].countChild = segment[idx*2+1].countChild + segment[idx*2+2].countChild;
    for(int i=0;i<32;i++) {
        segment[idx].val[i] = (segment[idx*2+1].val[i] + segment[idx*2+2].val[i]);
    }
}

void update(int idx, int low, int high, int val, int qlow, int qhigh) {
    updateLazy(idx, low, high);
    if(qlow > high || qhigh < low) return;
    else if(qlow <= low && high <= qhigh) {
        segment[idx].lazy = val;
        updateLazy(idx, low, high);
    } else {
        int mid = (low+high)/2;
        update(idx*2+1, low, mid, val, qlow, qhigh);
        update(idx*2+2, mid+1, high, val, qlow, qhigh);
        for(int i=0;i<32;i++) {
            segment[idx].val[i] = (segment[idx*2+1].val[i] + segment[idx*2+2].val[i]);
        }
    }
}

ll query(int idx, int low, int high, int qlow, int qhigh) {
    updateLazy(idx, low, high);
    if(qlow > high || qhigh < low) return 0;
    else if(qlow <= low && high <= qhigh) {
        return segment[idx].getSum();
    }
    int mid = (low+high)/2;
    return query(idx*2+1, low, mid, qlow, qhigh) + query(idx*2+2, mid+1, high, qlow, qhigh);
}

void init() {
    segment.assign(4*n, Node());
    build(0, 0, n-1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    vals.assign(n, 0);
    for(int i=0;i<n;i++) cin >> vals[i];
    cin >> q;
    init();
    for(int i=0;i<q;i++) {
        cin >> o;
        if(o==1) {
            cin >> l >> r;
            l--; r--;
            cout << query(0, 0, n-1, l, r) << "\n";
        } else {
            cin >> l >> r >> x;
            l--; r--;
            update(0, 0, n-1, x, l, r);
        }
    }
}
