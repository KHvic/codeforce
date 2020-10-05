#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 505;

int n, m, b, mod, v;
ll dp[MAXN][MAXN];
vector<int> vals;

int main()
{
    fastio
    cin >> n >> m >> b >> mod;
    for(int i=0;i<n;i++) {
        cin >> v;
        vals.push_back(v);
    }
    dp[0][0] = 1;
    for(int i=1;i<=n;i++) { // ppl
        for(int j=0;j<=m;j++) { // work left
            for(int k=0;k<=b;k++) { // bugs left
                if(j > 0 && k-vals[i-1] >= 0) {
                    dp[j][k] = (dp[j][k] + dp[j-1][k-vals[i-1]]) % mod;
                }
            }
        }
    }
    ll res = 0;
    for(int i=0;i<=b;i++) res = (res+dp[m][i]) % mod;
    cout << res;
}
