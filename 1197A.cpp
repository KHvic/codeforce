#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, v;
    cin >> t;
    while(t--) {
        cin >> n;
        int mx1 = 0, mx2 = 0;
        for(int i=0;i<n;i++) {
            cin >> v;
            if(v > mx1) {
                mx2 = mx1;
                mx1 = v;
            } else if(v > mx2) mx2 = v;
        }
        int res = min(mx2-1, n-2);
        cout << res << "\n";
    }
}
