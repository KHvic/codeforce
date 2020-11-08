#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll a, b, c;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        // case 1
        int res1 = a>=c ? -1 : 1;
        int res2 = c>=a*b ? -1 : b;
        cout << res1 << " " << res2 << "\n";
    }
}
