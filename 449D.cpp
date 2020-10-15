#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int mod = 1e9+7, MAXN = 1<<20;
int f[MAXN+10], pow2[MAXN+10]; // count of number a such that a&i == i

int main(){
    fastio
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        f[vals[i]]++;
    }
    pow2[0] = 1;
    for(int i=1;i<=MAXN;i++) pow2[i] = pow2[i-1]*2%mod;
    // dp to compute f[x]
    // f[x] = f[x] + f[x^(1<<i)] if ith bit is 0
    for(int i=0;i<20;i++) // order is important, else we could update some state too many times
        for(int j=MAXN-1;j>=0;j--)
            if(j&(1<<i))
                (f[j^(1<<i)] += f[j]) %= mod;
    // principle of inclusion exclusion
    // => T - sum(s[i]) + sum(intersect(s[i],s[j]) - sum(intersect(s[i],s[j],s[k]))
    // to get a subset of intersect we can use 2^f[i], number of items s.t x&i == i
    ll res = 0;
    for(int i=0;i<MAXN;i++) {
        int bitcount = __builtin_popcount(i);
        int sign = bitcount&1 ? -1 : 1;
        res = (res+sign*pow2[f[i]]) % mod;
    }
    cout << (res+mod)%mod;
}
