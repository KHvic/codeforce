#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// union find next position

vector<int> nxt;

int find(int x) {
    return nxt[x] == x ? x : nxt[x] = find(nxt[x]);
}

int main()
{
    fastio
    int n, m, l, r, x;
    cin >> n >> m;
    vector<int> res(n+1);
    nxt.assign(n+2, 0);
    for(int i=0;i<=n+1;i++) nxt[i] = i;
    while(m--) {
        cin >> l >> r >> x;
        int cur = find(l);
        while(cur<=r) {
            res[cur] = x;
            if(cur<=x) nxt[cur] = x;
            else nxt[cur] = find(r+1);
            cur = find(cur+1);
        }
        res[x] = 0;
    }
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
}
