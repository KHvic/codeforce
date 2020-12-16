#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n, k, s;
    cin >> n >> k >> s;
    ll mn = k, mx = (n-1)*k;
    if(s<mn || s > mx) {
        cout << "NO"; return 0;
    }
    cout << "YES\n";
    for(int i=1,cur=1;i<=k;i++) {
        ll left = k-i;
        ll take = min(s-left, n-1);
        s -= take;
        if(i%2) {
            // go right
            cur += take;
        } else {
            // go left
            cur -= take;
        }
        cout << cur << " \n"[i==k];
    }
}
