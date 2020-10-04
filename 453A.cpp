#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    double m, n;
    cin >> m >> n;
    double last = 0, res = 0;
    for(int i=1;i<=m;i++) {
        double nxt = pow((double)i/m, n);
        res += i * (nxt - last); // expected_value * times
        last = nxt;
    }
    cout << fixed << setprecision(10) << res;
}
