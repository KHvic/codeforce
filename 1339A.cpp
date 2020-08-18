#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,v;
    cin >> tc;
    while(tc--) {
        set<int> vals;
        cin >> n;
        while(n--) {
            cin >> v;
            vals.insert(v);
        }
        bool ok = true;
        int prev = -1;
        for(auto it=vals.begin();it!=vals.end()&&ok;it++) {
            if(prev>=0 && *it != prev+1) ok = false;
            prev = *it;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
