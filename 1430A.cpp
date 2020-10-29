#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        bool ok = false;
        for(int i=0;3*i<=n&&!ok;i++) {
            for(int j=0;5*j+i*3<=n&&!ok;j++){
                int left = n - 3*i - 5*j;
                if(left%7 == 0) {
                    ok = true;
                    cout << i << " " << j << " " << left/7 << "\n";
                }
            }
        }
        if(!ok) cout << -1 << "\n";
    }
}
