#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        int n = s.size();
        ll cur = 0, res = n;
        set<ll> ss;
        for(int i=0;i<n;i++) {
            char c = s[i];
            cur += c=='+' ? 1 : -1;
            if(cur<0 && !ss.count(cur)) {
                ss.insert(cur);
                res += (i+1);
            }
        }
        cout << res << "\n";
    }
}
