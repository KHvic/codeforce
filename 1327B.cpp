#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, v, k;
    cin >> t;
    while(t--) {
        cin >> n;
        set<int> s;
        for(int i=1;i<=n;i++) {
            s.insert(i);
        }
        int daughter = -1;
        for(int i=0;i<n;i++) {
            cin >> k;
            bool ok = false;
            for(int j=0;j<k;j++) {
                cin >> v;
                if(!ok && s.count(v)) {
                    ok = true;
                    s.erase(v);
                }
            }
            if(!ok) daughter = i+1;
        }
        if(daughter == -1) cout << "OPTIMAL\n";
        else {
            cout << "IMPROVE\n";
            cout << daughter << " " << *s.begin() << "\n";
        }
    }
}
