#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,a,b;
    cin >> n >> a >> b;
    n *= 6;
    if(a*b >= n) {
        cout << a*b << "\n";
        cout << a << " " << b;
        return 0;
    }
    bool swapped = 0;
    if(b<a) {swap(a,b); swapped=1;}
    ll best=1e18, besta=a,bestb=b;
    for(ll na=a;na*na<=n;na++) {
        ll nb = ceil(1.0*n/na);
        if(nb<b) continue;
        ll area = na*nb;
        if(area>=n && area<best) {
            best = area;
            besta = na, bestb = nb;
        }
    }
    if(swapped) swap(besta,bestb);
    cout << best << "\n" << besta << " " << bestb;
}
