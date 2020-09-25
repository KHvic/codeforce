#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll mod = 1e9+7;

struct FT {
    vector<ll> ft;
    int n;
    FT(int n):n(n) {ft.assign(n+1, 0);}
    void adjust(int idx, ll v) {
        for(idx++;idx<=n;idx+=(idx&-idx)) ft[idx]=(ft[idx]+v)%mod;
    }
    ll query(int idx) {
        ll res = 0;
        for(idx++;idx>0;idx-=(idx&-idx)) res=(res+ft[idx])%mod;
        return res;
    }
    ll query(int lo, int hi) {
        return query(hi) - query(lo-1);
    }
};

int main()
{
    fastio
    int n;
    ll v;
    cin >> n;
    FT ft(1e6+5);
    while(n--) {
        cin >> v;
        ll newSeq = (ft.query(v)+1)*v%mod;
        newSeq += -ft.query(v, v) + mod;
        newSeq %= mod;
        ft.adjust(v, newSeq);
    }
    cout << ft.query(1e6);
}
