#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t, n, r;
    cin >> t;
    while(t--) {
        cin >> n >> r;
        // case1: for r < n, foreach r, we can have r shapes
        // case2: for n <= r, only 1 shape for such r
        ll res = 0;
        if(r >= n) {
            res++;
            r = n-1; // make case2 become case1
        }
        // 1+2+3..+r
        res += (r+1)*(r)/2;
        cout << res << "\n";
    }
}
