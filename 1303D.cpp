#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll n, m, v;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> cnt(64);
        for(int i=0;i<m;i++) {
            cin >> v;
            int pos = __builtin_ctz(v);
            cnt[pos]++;
        }
        int res = 0;
        bool ok = true;
        for(int i=0;i<63;i++) {
            if(n&(1LL<<i)) {
                if(cnt[i]==0) {
                    int j=i;
                    while(j<63&&cnt[j] == 0) {
                        cnt[j++] += 1;
                    }
                    if(j==63) {
                        ok = false; break;
                    }
                    cnt[j] -= 1;
                    res += j-i;
                }
                cnt[i] -= 1;
            }
            cnt[i+1] += cnt[i]/2;
        }
        cout << (ok ? res : -1) << "\n";
    }
}
