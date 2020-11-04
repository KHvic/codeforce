#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        if(vals[0] + vals[1] > vals.back()) cout << "-1\n";
        else cout << 1 << " " << 2 << " " << n << "\n";
    }
}
