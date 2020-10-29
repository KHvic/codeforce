#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// the largest number A that satisfy l%A >= A/2 is l*2 (exactly twice of l)
// just check is 2*l > r, if so r%(2*l) = r >= l, which satisfy the contraint

int main(){
    fastio
    int t, l, r;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(2*l > r) cout << "YES\n";
        else cout << "NO\n";
    }
}
