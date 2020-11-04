#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 3005;
ll cnt[MAXN][MAXN];

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        ll res = 0;
        // count number (i,j) == (k,l)
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                res += cnt[vals[i]][vals[j]];
            }
            for(int j=0;j<i;j++) {
                cnt[vals[j]][vals[i]]++;
            }
        }
        cout << res << "\n";
    }
}
