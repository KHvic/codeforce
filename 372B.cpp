#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int n,m,q;
    int a,b,c,d;
    cin >> n >> m >> q;
    vector<string> grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];

    vector<vector<int>> sum(n+1, vector<int>(m+1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (grid[i][j]-'0');
        }
    }
    function<int(int, int, int, int)> query = [&](int a, int b, int c, int d) -> int {
        return sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1];
    };

    int dp[n+5][m+5][n+5][m+5];
    memset(dp, 0, sizeof dp);
    // start from smaller sized rectangle
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            for(int k=i;k<=n;k++)
                for(int l=j;l<=m;l++){
                    int &subres = dp[i][j][k][l];
                    subres = query(i,j,k,l) == 0; // add one if entire rect is 0
                    // inclusion exclusion principle for counting from previosly computed states
                    // add for odd count bits, subtract even bits
                    for(int bits=1;bits<(1<<4);bits++) {
                        subres += ((__builtin_popcount(bits)%2) ? 1 : -1)*
                        dp[i+!!(bits&0b1)][j+!!(bits&0b10)][k-!!(bits&0b100)][l-!!(bits&0b1000)];
                    }
                }

    while(q--) {
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << "\n";
    }
}
