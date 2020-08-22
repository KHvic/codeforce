#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll n;
    cin >> n;
    vector<ll> vals(n);
    for(int i=0;i<n;i++) cin >> vals[i];
    sort(vals.begin(), vals.end(), greater<ll>());
    ll res = 0;
    for(int m=1;m<=n;m*=4){
        res += accumulate(vals.begin(), vals.begin() + m, 0LL);
    }
    cout << res;
}
