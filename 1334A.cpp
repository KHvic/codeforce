#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, p, c;
    cin >> t;
    while(t--) {
        cin >> n;
        int prevp, prevc;
        bool ok = true;
        for(int i=0;i<n;i++) {
            cin >> p >> c;
            if(i) {
                int diffp = p-prevp, diffc = c-prevc;
                ok &= (diffp >= 0 && diffc >= 0 && diffc <= diffp);
            }
            ok &= (c<=p);
            prevp = p, prevc = c;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
