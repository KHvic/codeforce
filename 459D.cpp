#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

vector<int> fenwick;

void init() {
    fenwick.assign(n+1, 0);
}

void adjust(int idx, int v) {
    idx++;
    while(idx<=n) {
        fenwick[idx] += v;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    idx++;
    int res = 0;
    while(idx) {
        res += fenwick[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    init();
    vector<int> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    unordered_map<int, int> cnt;
    unordered_map<int, int> cnt2;
    for(int i=n-1;i>=0;i--) {
        int freq = ++cnt[vals[i]];
        adjust(freq, 1);
    }
    ll res = 0;
    for(int i=0;i<n;i++) {
        int exclude_freq = cnt[vals[i]]--;
        adjust(exclude_freq, -1);
        int left_freq = ++cnt2[vals[i]];
        res += query(left_freq-1);
    }
    cout << res;
}
