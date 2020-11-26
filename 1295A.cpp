#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        string res;
        cin >> n;
        if(n&1) {
            res += '7';
            n -= 3;
        }
        res += string(n/2, '1');
        cout << res << "\n";
    }
}
