#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

// observation, a and b is small
// only need to care about x % a*b since (a*b % a*b) == (0 % a*b)

vector<int> psum;

void build(int a, int b) {
    int len = a*b;
    psum.assign(len, 0);
    for(int i=1;i<len;i++) {
        psum[i] = psum[i-1];
        if(i%a%b != i%b%a) psum[i]++;
    }
}

ll query(ll x, int len) {
    ll times = x/len;
    ll rem = x%len;
    return times*psum.back() + psum[rem];
}

ll query(ll l, ll r, int len) {
   return query(r, len) - query(l-1, len);
}

int main(){
    fastio
    int t, a, b, q;
    ll l, r;
    cin >> t;
    while(t--) {
        cin >> a >> b >> q;
        build(a, b);
        for(int i=0;i<q;i++) {
            cin >> l >> r;
            cout << query(l, r, a*b) << " \n"[i==q-1];
        }
    }
}
