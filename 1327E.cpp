#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll MOD = 998244353, MAXN = 1e7;
ll pow10[MAXN];

int main(){
    fastio
    int n;
    cin >> n;
    pow10[0] = 1;
    for(int i=1;i<=n;i++) pow10[i] = pow10[i-1] * 10 % MOD;

    for(int i=1;i<=n;i++) {
        ll ways;
        if(i==n) ways = 10;
        else {
            ll waysSide = 2LL*10LL*9LL*pow10[n-i-1] % MOD;
            ll waysMid = 10LL*(n-i+1-2)*9*9 % MOD * pow10[n-i-2] % MOD;
            ways = (waysSide + waysMid) % MOD;
        }
        cout << ways << " \n"[i==n];
    }
}
