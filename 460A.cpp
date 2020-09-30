#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fastio
    int n, m;
    cin >> n >> m;
    int res = 0;
    // imagine it as bottles
    // n filled bottle = n unit of water + n empty bottled
    // m empty bottles = 1 filled bottle = 1 empty bottle + 1 unit of water
    // thus, m-1 empty bottles = 1 unit of water
    // n filled bottle = n unit of water + (n-1)/(m-1) unit of water <- subtract 1 from n because we have to round down (consider case of n=4, m=5)
    // can simply imagine that we actually need 1 spare empty bottle at all times for the exchange (hence the minus 1)
    res = n + (n-1)/(m-1);
    cout << res;
}
