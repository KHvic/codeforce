#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 105, MAXM = 20005, OFFSET = 10000, INF = -1e7;
int dp[MAXN][MAXM];
int n, k;
int A[MAXN], B[MAXN];

int main()
{
    fastio

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];

    for(int i=0;i<=n;i++)
    for(int j=0;j<MAXM;j++) dp[i][j] = INF;

    dp[0][OFFSET] = 0;
    for(int i=0;i<n;i++) {
        int a = A[i], b = B[i];
        int add = k*b - a;
        for(int j=0;j<MAXM;j++) {
            dp[i+1][j] = dp[i][j];
            if(j-add>=0 && j-add<MAXM) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-add] + a);
            }
        }
    }
    int res = dp[n][OFFSET];
    cout << (res<=0 ? -1 : res);
}
