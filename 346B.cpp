#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

string a, b, c;
vector<int> bt;

void kmp() {
    bt.assign(c.size()+1, 0);
    int i=0, j=-1;
    bt[0] = -1;
    while(i<c.size()) {
        while(j>=0 && c[j] != c[i]) j = bt[j];
        bt[++i] = ++j;
    }
}

const int MAXN = 101;
int dp[MAXN][MAXN][MAXN];

int n,m,l;

int solve(int i, int j, int k) {
    if(k==l) return -1e8;
    else if(i>=n || j>=m) return 0;
    else if(dp[i][j][k] != -1) return dp[i][j][k];

    int res = max(solve(i+1, j, k), solve(i, j+1, k));
    if(a[i] == b[j]) {
        int nk = k;
        while(nk>=0 && c[nk] != a[i]) nk = bt[nk];
        int res2 = solve(i+1, j+1, nk+1) + 1;
        res = max(res, res2);
    }
    return dp[i][j][k] = res;
}

void print(int i, int j, int k) {
    if(i>=n || j>=m) return;
    if(dp[i][j][k] == dp[i+1][j][k]) print(i+1, j, k);
    else if(dp[i][j][k] == dp[i][j+1][k]) print(i, j+1, k);
    else {
        cout << a[i];
        int nk = k;
        while(nk>=0 && c[nk] != a[i]) nk = bt[nk];
        print(i+1, j+1, nk+1);
    }
}

int main(){
    fastio
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), l = c.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<l;k++)
                dp[i][j][k] = -1;
    kmp();

    int res = solve(0, 0, 0);
    if(res==0) cout << "0";
    else print(0, 0, 0);
}
