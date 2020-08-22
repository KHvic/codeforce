#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    ll vals[3];
    for(int i=0;i<3;i++) cin >> vals[i];
    sort(vals, vals+3);
    ll res = accumulate(vals, vals+3, 0LL)/3;
    // imagine if we have infinite of vals[2], then we are limited by vals[0]+vals[1]
    // in this case we always use 2 of vals[2], and in total, we need 2*(vals[0]+vals[1]) of vals[2]
    // so result is limited by this amount
    if(vals[0]+vals[1]<res) res = vals[0]+vals[1];

    cout << res;
}
