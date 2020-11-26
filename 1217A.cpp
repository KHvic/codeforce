#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll s, i, e;
    cin >> t;
    while(t--) {
        cin >> s >> i >> e;
        ll mx = s + e;

        ll mn = max(i+1, s); // bump str up to min
        ll use_str = mn-s;
        ll left = e - use_str;
        if(left<0) {
            cout << "0\n"; continue;
        }
        ll use_int = min(mn-1-i, left); // allocate as many to int as possible
        left -= use_int;
        mn += left/2 + (left&1);
        ll res = max(mx-mn+1, 0LL);
        cout << res << "\n";
    }
}
