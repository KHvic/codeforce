#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

ll dp[2005][2005];
int vals[2005];
int n, h;
const int mod = 1e9+7;

inline void add(ll &a, ll b) {
    a += b;
    a %= mod;
}

int main()
{
    fastio
    cin >> n >> h;
    for(int i=1;i<=n;i++) {
        cin >> vals[i];
        if(vals[i] > h) {
            cout << 0;
            return 0;
        }
    }
    dp[0][0] = 1;

    for(int i=1;i<=n;i++) {
        int need = h - vals[i];
        // max number of opened segments so far is i
        for(int open=0; open <= min(i, need); open++) {
            // case 1: open match need
            if(open == need) {
                add(dp[i][open], dp[i-1][open]); // - nothing happen on i
                if(open) add(dp[i][open], dp[i-1][open-1]); // [ open new segment at i
            }
            // case 2: open = need-1, have one less open than need after i
            // basically closing open at i
            if(open+1 == need) {
                add(dp[i][open], dp[i-1][open+1]*(open+1)); // ] close one of the opened segment after i
                add(dp[i][open], dp[i-1][open]); // [] open and close after i
                add(dp[i][open], dp[i-1][open]*open); // ][ close one of opened segment then open at i
            }
        }
    }
    cout << dp[n][0];
}
