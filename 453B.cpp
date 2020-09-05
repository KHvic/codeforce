#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> primes;

void sieve() {
    vector<int> isprime(60,1);
    for(int i=2;i<60;i++) {
        if(!isprime[i]) continue;
        for(int j=i*i;j<60;j+=i) isprime[j] = false;
        primes.push_back(i);
    }
}

int main(){
    fastio
    sieve();
    int n;
    cin >> n;
    vector<int> vals(n);
    vector<int> divisorBits(60);
    int numPrimes = primes.size();
    for(int i=0;i<n;i++) {
        cin >> vals[i];
    }
    for(int i=2;i<60;i++) {
        int bits = 0;
        for(int j=0;j<numPrimes;j++) {
            if(i % primes[j] == 0) bits |= (1<<j);
        }
        divisorBits[i] = bits;
    }
    // dp
    vector<vector<int>> dp(n+1,vector<int>(1<<numPrimes, 1e7));
    vector<vector<int>> pre(n+1,vector<int>(1<<numPrimes));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<60;j++) {
            int nondivisorBits = ~divisorBits[j] & ((1<<numPrimes) - 1);
            // iterate all bits combination excluding divisorBits
            for(int k=nondivisorBits;;k=(k-1)&nondivisorBits) {
                int cost = dp[i-1][k] + abs(vals[i-1]-j);
                int nxtBits = k | divisorBits[j];
                if(cost < dp[i][nxtBits]) {
                    dp[i][nxtBits] = cost;
                    pre[i][nxtBits] = j;
                }
                if(k==0) break;
            }
        }
    }
    int bestBits = min_element(dp[n].begin(), dp[n].end()) - dp[n].begin();
    function<void(int, int)> print = [&](int idx, int bits) {
        if(idx<=0) return;
        int prev = pre[idx][bits];
        print(idx-1, bits&(~divisorBits[prev]));
        cout << prev << " \n"[idx==n];
    };
    print(n, bestBits);
}
