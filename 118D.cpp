#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 105;
const ll mod = 1e8;
int n1,n2,k1,k2;
ll dp[MAXN][MAXN][2];

ll solve(int a, int b, int cur) {
    if(a==0 && b==0) return 1;
    else if(dp[a][b][cur] != -1) return dp[a][b][cur];
    ll res = 0;
    for(int i=1;i<=(cur ? min(b,k2) : min(a,k1));i++) {
        int na = a;
        int nb = b;
        if(cur) nb -= i;
        else na -= i;
        res = (res+solve(na,nb,cur^1)) % mod;
    }

    return dp[a][b][cur] = res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof dp);

    cout << (solve(n1, n2, 0) + solve(n1, n2, 1)) % mod;
}
