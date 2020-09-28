#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1005, MAXK=105;
ll pow10k[MAXN], pow10m[MAXN];
ll dp[MAXN][MAXK][2];
int n, k, m;

// dp, build suffix from right to left until fit criteria

ll solve(int idx, int left, int zero) {
    if(left==0 && !zero) {
        int prefix_len = n-idx;
        return prefix_len == 0 ? 1 : 9LL*pow10m[prefix_len-1]%m;
    }
    else if(idx>=n) return 0;
    else if(dp[idx][left][zero] != -1) return dp[idx][left][zero];
    ll res = 0;
    for(int i=0;i<10;i++) {
        ll add = pow10k[idx]*i%k;
        ll nleft = (add+left)%k;
        res = (res+solve(idx+1,nleft, i==0))%m;
    }
    return dp[idx][left][zero] = res;
}

int main()
{
    fastio
    cin >> n >> k >> m;
    pow10k[0] = 1, pow10m[0] = 1;
    for(int i=1;i<=n;i++) {
        pow10k[i] = (pow10k[i-1]*10)%k;
        pow10m[i] = (pow10m[i-1]*10)%m;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 1);
}
