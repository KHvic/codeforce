#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main()
{
    fastio
    ll l, r;
    cin >> l >> r;
    if (l % 2 != 0) l++;

    if (l + 2 > r) cout << -1;
    else cout << l << " " << l+1 << " " << l+2;
}
