#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, m, x, y;
    cin >> n >> m;
    int res = -1;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        if(x*100+y > m*100) continue;
        res = max(res, (100-y)%100);
    }
    cout << res;
}
