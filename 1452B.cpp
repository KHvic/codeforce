#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> vals(n);
        ll mx = 0, sum = 0;
        for(int i=0;i<n;i++) {
            cin >> vals[i];
            mx = max(mx, vals[i]);
            sum += vals[i];
        }
        ll cost = 0;
        // condition 1: sum has to be divisible by n-1
        int rem = sum%(n-1);
        if(rem) cost += n-1-rem;
        sum += cost;
        // condition 2: sum/(n-1) has to be >= mx
        ll mnSum = mx*(n-1);
        cost += max(0LL, mnSum - sum);
        cout << cost << "\n";
    }
}
