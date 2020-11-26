#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll f(ll x) {return x*x;}

int main(){
    fastio
    int n;
    ll c, sum;
    cin >> n;
    while(n--) {
        cin >> c >> sum;
        ll split = sum/c;
        ll rem = sum - split*c;
        ll res = rem*f(split+1) + (c-rem)*f(split);
        cout << res << "\n";
    }
}
