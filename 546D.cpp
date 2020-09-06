#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 5000001;
int count_divisors[MAXN], divisor[MAXN];
ll prefix_sum[MAXN];

void sieve() {
    bitset<MAXN> bs;
    bs.set();
    for(ll i=2;i<MAXN;i++) {
        if(bs[i]) {
            for(ll j=i*i;j<MAXN;j+=i) {
                divisor[j] = i;
                bs.reset(j);
            }
            divisor[i] = i;
        }
    }
    for(int i=2;i<MAXN;i++) {
        count_divisors[i] = count_divisors[i/divisor[i]] + 1;
        prefix_sum[i] = prefix_sum[i-1] + count_divisors[i];
    }
}


int main(){
    fastio
    sieve();
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> b >> a;
        cout << prefix_sum[b] - prefix_sum[a] << "\n";
    }
}
