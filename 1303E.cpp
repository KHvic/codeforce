#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int tc;
    string s, t;
    cin >> tc;
    while(tc--) {
        cin >> s >> t;
        int n = s.size(), m = t.size();
        vector<vector<int>> nxt(n+1, vector<int>(26, 1e8));
        for(int i=n-1;i>=0;i--) {
            nxt[i] = nxt[i+1];
            nxt[i][s[i]-'a'] = i;
        }
        bool ok = false;
        for(int i=0;i<=m&&!ok;i++) {
            string a = t.substr(0, i), b = t.substr(i);
            int alen = a.size(), blen = b.size();
            vector<vector<int>> dp(alen+1, vector<int>(blen+1, 1e8));
            dp[0][0] = 0;
            for(int j=0;j<=alen;j++) {
                for(int k=0;k<=blen;k++) {
                    int pos = dp[j][k];
                    if(pos >= n) continue;
                    if(j+1<=alen) dp[j+1][k] = min(dp[j+1][k], nxt[pos][a[j]-'a']+1);
                    if(k+1<=blen) dp[j][k+1] = min(dp[j][k+1], nxt[pos][b[k]-'a']+1);
                }
            }
            ok |= dp[alen][blen] <= n;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
