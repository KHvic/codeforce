#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n;
    ll p;
    cin >> n >> p;
    vector<pair<ll, ll>> sharks(n);
    for(int i=0;i<n;i++) cin >> sharks[i].first >> sharks[i].second;
    double res = 0;

    auto countDivisibleP = [&](ll a, ll b) {
        return b/p - (a-1)/p;
    };

    auto computeProb = [&](pair<ll, ll> a, pair<ll, ll> b) -> double {
        double lenA = a.second - a.first + 1, lenB = b.second - b.first + 1;
        ll countA = countDivisibleP(a.first, a.second), countB = countDivisibleP(b.first, b.second);
        double probA = countA/lenA, probB = countB/lenB; // prob A/B is divisible by P
        return probA + probB - probA*probB; // inclusion-exclusion
    };

    // linearity of expectation, sum each E(x)
    for(int i=0;i<n;i++) {
        int left = (i+(n-1)) % n, right = (i+1) % n;
        double probA = computeProb(sharks[i], sharks[left]);
        double probB = computeProb(sharks[i], sharks[right]);
        res += (probA+probB)*1000;
    }
    cout << fixed << setprecision(10) << res;
}
