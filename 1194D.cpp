#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool win;
        if(k%3==0) {
            // x*k position is winning now for any x
            // k=6, LWWLWWW LWWLWWW ...
            n %= (k+1); // split into k+1 cycle
            // win if at k position or not divislbe by 3
            win = n%3==0 && n!=k ? false : true;
        } else {
            // LWWLWWLWW...
            win = n%3==0 ? false : true;
        }
        cout << (win ? "Alice\n" : "Bob\n");
    }
}
