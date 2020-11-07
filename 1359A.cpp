#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, m, k;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        int per = n/k;
        int mx = min(per, m);
        int remain = m - mx;
        int mx2 = remain/(k-1);
        mx2 += (remain % (k-1) != 0);
        cout << (mx-mx2) << "\n";
    }
}
