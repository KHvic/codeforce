#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int n,k,v;
int a=0,b=0;
const ll mod = 1e9+7;

inline void add(ll &v1, ll v2) {
    v1 += v2;
    v1 %= mod;
}

const int MAXN = 52;
int shortest;

ll fac[MAXN], inv[MAXN];

ll powe(ll x, ll e) {
    ll res = 1;
    while(e) {
        if(e&1) res=res*x%mod;
        e >>= 1;
        x = x*x%mod;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for(int i=1;i<MAXN;i++) fac[i] = fac[i-1]*i%mod;
    inv[MAXN-1] = powe(fac[MAXN-1], mod-2);
    for(int i=MAXN-2;i>=0;i--) inv[i] = inv[i+1] * (i+1) % mod;
}

inline ll choose(int a, int b) {
    return fac[a]*inv[a-b]%mod*inv[b]%mod;
}

typedef tuple<int, int, int> ti;
ll dp[MAXN][MAXN][2];
ll dist[MAXN][MAXN][2];

int main()
{
    fastio
    init();
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> v;
        if(v==50) a++;
        else b++;
    }
    memset(dist, 0x3f, sizeof dp);
    queue<ti> q;
    q.push(make_tuple(a, b, 0));
    dp[a][b][0] = 1;
    int x,y,z,x2,y2,z2;
    bool ok = false;
    int steps = 0;
    while(!q.empty() && !ok) {
        for(int len=q.size();len>0;len--) {
            tie(x,y,z) = q.front(); q.pop();
            x2=a-x,y2=b-y,z2=!z;
            if(x==a && y==b && z==1) {
                ok = true;
            }
            for(int i=0;i<=x;i++) {
                int costA=i*50;
                ll waysA = choose(x, i);
                if(costA > k) break;
                for(int j=0;j<=y;j++) {
                    if(i==0&&j==0) continue;
                    int costB = j*100;
                    if(costA+costB > k) break;
                    ll waysB = choose(y, j);
                    int x3=x2+i,y3=y2+j;
                    if(steps+1 < dist[x3][y3][z2]) {
                        dist[x3][y3][z2] = steps+1;
                        q.push(make_tuple(x3, y3, z2));
                    }
                    if(steps+1 == dist[x3][y3][z2]) {
                        add(dp[x3][y3][z2], waysA*waysB%mod*dp[x][y][z]%mod);
                    }
                }
            }
        }
        steps++;
    }
    if(!ok) {
        cout << -1 << "\n" << 0;
    } else {
        cout << dist[a][b][1] << "\n" << dp[a][b][1];
    }
}
