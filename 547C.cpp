#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<vector<int>> primes;
int cnt[500005];
vector<bool> on;
ll res = 0;

void addPrimes(int x) {
    vector<int> prime;
    for(ll i=2;i*i<=x;i++)
    if(x%i == 0) {
        prime.push_back(i);
        while(x%i==0) x/=i;
    }
    if(x>1) prime.push_back(x);
    primes.push_back(prime);
}

void update(int idx) {
    on[idx] = !on[idx];
    int sign = on[idx] ? 1 : -1;
    // principle of inclusion exclusion
    // when we add, we want to count numbers of pair such that gcd(A[idx], a) == 1
    // we can do so by considering the existing counter
    // = cnt[1] - cnt[p1] - cnt[p2] ... + cnt[p1*p2] ... - cnt[p1*p2*p3] ...
    // when we remove, we want to count numbers of such pairs and remove them instead
    // = -(equation_above)
    // where cnt[x] is number of existing number a with x as a divisor
    for(int b=0;b<(1<<primes[idx].size());b++) {
        int mul = 1;
        int bitcount = __builtin_popcount(b);
        for(int i=0;i<primes[idx].size();i++)
            if(b&(1<<i)) mul *= primes[idx][i];

        if(!on[idx]) cnt[mul]--;
        int sign2 = bitcount&1 ? -1 : 1;
        res += 1LL*sign*sign2*cnt[mul];
        if(on[idx]) cnt[mul]++;
    }
}

int main(){
    fastio
    int n, m, v;
    cin >> n >> m;
    on.assign(n, false);
    for(int i=0;i<n;i++) {
        cin >> v;
        addPrimes(v);
    }

    while(m--) {
        cin >> v; v--;
        update(v);
        cout << res << "\n";
    }
}
