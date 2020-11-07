#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];
        bool ok = false;
        for(int i=1;i<n-1&&!ok;i++)
        if(vals[i] > vals[i-1] && vals[i] > vals[i+1]) {
            ok = true;
            cout << "YES\n" << i << " " << i+1 << " " << i+2 << "\n";
        }
        if(!ok) cout << "NO\n";
    }
}
