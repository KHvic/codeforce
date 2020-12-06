#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n, m, v;
    cin >> n >> m;
    vector<int> rows(n), cols(m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> v;
            if(v) rows[i]++, cols[j]++;
        }
    }
    ll res = 0;
    for(int x : rows) {
        ll black = x, white = m - x;
        res += (1LL << black) - 1;
        res += (1LL << white) - 1;
    }
    for(int x : cols) {
        ll black = x, white = n - x;
        res += (1LL << black) - 1;
        res += (1LL << white) - 1;
    }
    res -= n*m;
    cout << res;
}
