#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef tuple<int,int,int> ti;
string s;
int n, m, l, r;
vector<ti> segment;

ti combine(ti a, ti b) {
    int l1, l2, r1, r2, t1, t2;
    tie(l1,r1,t1) = a, tie(l2,r2,t2) = b;
    int take = min(l1, r2);
    l1 -= take; r2 -= take;
    return make_tuple(l1+l2, r1+r2, take+t1+t2);
}

void buildRecurse(int idx, int low, int high) {
    if(low==high) {
        segment[idx] = make_tuple(s[low] == '(', s[high] == ')', 0);
    } else {
        int mid = (low+high) >> 1;
        buildRecurse(idx*2+1, low, mid);
        buildRecurse(idx*2+2, mid+1, high);
        segment[idx] = combine(segment[idx*2+1], segment[idx*2+2]);
    }
}

void build() {
    n = s.size();
    segment.assign(4*n, ti(0,0,0));
    buildRecurse(0, 0, n-1);
}

ti queryRecurse(int idx, int low, int high, int qlow, int qhigh) {
    if(high<qlow || low>qhigh) {
        return make_tuple(0,0,0);
    } else if(low>=qlow && high<=qhigh) {
        return segment[idx];
    }
    int mid = (low+high) >> 1;
    auto left = queryRecurse(idx*2+1, low, mid, qlow, qhigh);
    auto right = queryRecurse(idx*2+2, mid+1, high, qlow, qhigh);
    return combine(left, right);
}

int query(int low, int high) {
    return get<2>(queryRecurse(0, 0, n-1, low, high)) * 2;
}

int main(){
    fastio
    cin >> s;
    build();
    cin >> m;
    while(m--) {
        cin >> l >> r; l--; r--;
        cout << query(l, r) << "\n";
    }
}
