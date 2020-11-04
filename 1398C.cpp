#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        // find subarray such that prefix[r] - prefix[l] = r - l
        // prefix[r] - r = prefix[l] - l
        map<ll, ll> groups;
        groups[1] = 1; // default, 1 can pair with itself
        ll prefix = 0, res = 0;
        for(int i=0;i<n;i++) {
            int v = s[i]-'0';
            prefix += v;
            ll key = prefix-i;
            groups[key]++;
        }
        for(auto& p : groups) res += p.second*(p.second-1)/2;
        cout << res << "\n";
    }
}
