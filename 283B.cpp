#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);
}

const int MAXN = 1e6;
const ll INF = -1e15;
ll dp[MAXN][2]; // state: x, step number
int n;
ll a[MAXN];

ll solve(int x, int step) {
    if(x<=0 || x>n) return 0;
    else if(dp[x][step] != -1) return dp[x][step];
    dp[x][step] = INF;
    ll subres = a[x];
    if(step==0) subres += solve(x+a[x], 1);
    else subres += solve(x-a[x], 0);
    return dp[x][step] = subres;
}

int main()
{
    fastio
    cin >> n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<2;j++)
            dp[i][j] = -1;
    dp[1][0] = dp[1][1] = INF;
    for(int i=2;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<n;i++) {
        ll res = solve(1+i, 1) + i;
        cout << (res<=0 ? -1 : res) << "\n";
    }
}
