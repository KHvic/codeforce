#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

string s;
int m, n;
ll dp[1<<19][100];
ll fact[20];

int main(){
    fastio
    cin >> s >> m;

    fact[0] = 1;
    n = s.size();
    for(int i=1;i<=n;i++) fact[i] = fact[i-1] * i;
    dp[0][0] = 1;
    for(int mask=0;mask<(1<<n);mask++) {
        for(int prevm=0;prevm<m;prevm++) {
            if(dp[mask][prevm] == 0) continue;
            for(int pos=0;pos<n;pos++) {
                if(mask==0 && s[pos]=='0') continue;
                if(mask & (1<<pos)) continue;
                int nxtm = (prevm*10+(s[pos]-'0')) % m;
                dp[mask|(1<<pos)][nxtm] += dp[mask][prevm];
            }
        }
    }
    int digit_cnt[10] = {};
    for(char c : s) digit_cnt[c-'0']++;
    ll res = dp[(1<<n)-1][0];
    for(int x : digit_cnt) res /= fact[x];
    cout << res;
}
