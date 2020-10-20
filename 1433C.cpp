#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main(){
    fastio
    int t,n,v;
    cin >> t;
    while(t--) {
        cin >> n;
        set<int> s;
        vector<int> vals(n);
        int mx = 0;
        for(int i=0;i<n;i++) {
            cin >> v;
            vals[i] = v;
            s.insert(v);
            mx = max(mx, v);
        }
        int res = -1;
        if(s.size() > 1) {
            for(int i=0;i<n;i++) if(vals[i] == mx) {
                if((i!= 0 && vals[i-1] != mx) || (i!=n-1 && vals[i+1] != mx)) {
                    res = i+1;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
}
