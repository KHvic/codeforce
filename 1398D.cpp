#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const int MAXN = 205;

int r, g, b;
vector<int> rs, gs, bs;
ll dp[MAXN][MAXN][MAXN];

ll solve(int x, int y, int z) {
    bool hasX = x<r, hasY = y<g, hasZ = z<b;
    int left = hasX + hasY + hasZ;
    if(left<=1) return 0;
    else if(dp[x][y][z] != -1) return dp[x][y][z];
    ll res = 0;
    if(hasX && hasY) res = solve(x+1, y+1, z) + rs[x]*gs[y];
    if(hasX && hasZ) res = max(solve(x+1, y, z+1) + rs[x]*bs[z], res);
    if(hasY && hasZ) res = max(solve(x, y+1, z+1) + gs[y]*bs[z], res);

    return dp[x][y][z] = res;
}

int main(){
    fastio
    cin >> r >> g >> b;
    rs.assign(r, 0); gs.assign(g, 0); bs.assign(b, 0);
    for(int i=0;i<r;i++) cin >> rs[i];
    for(int i=0;i<g;i++) cin >> gs[i];
    for(int i=0;i<b;i++) cin >> bs[i];
    vector<vector<int>*> its = {&rs, &gs, &bs};
    for(auto it : its) sort(it->rbegin(), it->rend());
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0);
}
