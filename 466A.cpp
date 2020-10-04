#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int res = n*a;
    int times = n/m;
    int left = n%m;
    res = min(res, times*b + left*a);
    res = min(res, (times+1)*b);
    cout << res;
}
