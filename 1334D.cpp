#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// notice pattern n=4
// 121314, 2324, 34, 1
// n, n-2, n-4

vector<int> res;
void gen(ll l, ll r, ll idx, ll n, int offset=0) {
    for(int d=n;d>=0;d--) {
        if(idx>r) break;
        if(d==0) {
            res.push_back(1);
            return;
        }
        ll left = idx, right = idx+2*n-1;
        if(min(right, r) >= max(left, l)) {
            for(ll i=0,j=idx;i<n&&j<=r;i++,j+=2) {
                if(j>=l && j<=r) res.push_back(1+offset);
                if(j+1>=l && j+1<=r) res.push_back(i+2+offset);
            }
        }
        offset++;
        n--;
        idx = right+1;
    }
}

int main(){
    fastio
    int t;
    ll n, l, r;
    cin >> t;
    while(t--) {
        cin >> n >> l >> r;
        res.clear();
        gen(l-1, r-1, 0, n-1);
        for(int i=0;i<res.size();i++) cout << res[i] << " \n"[i==res.size()-1];
    }
}
